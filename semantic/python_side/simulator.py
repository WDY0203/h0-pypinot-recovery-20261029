# config
import pypinot.const
import json
g_config = {
    'combiner_name': './combiner.py',
    'simulator_name': 'bin/stockSimulator',
    'solver_name': 'external/bbsolver',
    'signal_file': '',
    'target_list': '',
    'predate': pypinot.const.predate,
    'dates': pypinot.const.dates,
    'static_data_dir': '/opt/bbcluster/alpha/extdata',
    'components': [
        {
            'name': 'bbsolver',
            'args': ['python3', ['solver_name'], '-', ['today'], ['today_'], ['addr'], ['port'], ['static_data_dir']],
            'input_field': 'config_json',
            'env' : {'OMP_NUM_THREADS': '1',
                     'PYTHONPATH': '/opt/bbcluster/alpha/python:/opt/bbcluster/alpha/pinot/pypinot_unstable.pyz'},
            'use_bus': True
        },
        {
            'name': 'simulator',
            'args': [['simulator_name'], '-c', ['addr'], '-p', ['port'],
                     '-x', ['target_cash_base'], ['signal_file'], ['target_list'], ['today']],

            'args2': [['simulator_name'], '-C', '-s', ['slice_file'], '-c', ['addr'], '-p', ['port'],
                      '-x', ['target_cash_base'], ['signal_file'], ['target_list'], ['today']],

            # XXX
            'args3': [['simulator_name'], '-s', ['slice_file'], '-c', ['addr'], '-p', ['port'],
                      '-x', ['target_cash_base'], ['signal_file'], ['target_list'], ['today']],
            'input_field': 'config_json',
            'use_bus': True
        },
        {
            'name': 'combiner',
            'args': [['combiner_name'], ['addr'], ['port'], ['today']],
            'env' : {'OMP_NUM_THREADS': '1',
                     'PYTHONPATH': '/opt/bbcluster/alpha/python:/opt/bbcluster/alpha/pinot/pypinot_unstable.pyz'},
            'input_field': 'config_json',
            'use_bus': True
        },
    ]
}

# main
import sys
import pandas as pd
import pypinot
import pypinot.config_parser
import pickle

def compute_hold_value(latest_slice, hold):
    return (latest_slice.reindex(hold.index)['price'] * hold['volume']).sum()

def compute_pnl(latest_slice, trade_log):
    return trade_log.apply(lambda x: (latest_slice.loc[x['code']]['price'] - x['price']) * x['volume'] * (1 if x['type'] == "B" else -1), axis = 1).sum()

def handle_dividend(hold, today):
    hold['volume'] /= hold.index.map(lambda x: pypinot.getRescale(x, today))

try:
    sys.path.append('/opt/bbcluster/alpha/pinot')
    import SimStubs2
except:
    pass

class SmallStepRunner:
    def __getstate__(self):
        state = self.__dict__.copy()
        state['pool'] = None
        return state

    def __setstate__(self, state):
        self.__dict__.update(state)

    def set_pool(self, pool):
        self.pool = pool

    def __init__(self, config, hold, usable, slicedir, target_cash_initial, hold_value_initial, save_prefix = None, pool = None, skip_first_dividend = False, skip_days = [],
                 sod_call = None, real_cash = 0.0):
        self.config = config

        # calculate days
        today_ = config['predate']
        days = []

        for today in config['dates']:
            if today < config['start_date']:
                today_ = today
                continue

            if today > config['end_date']:
                break

            days.append(today)

        self.target_cash_initial = target_cash_initial
        self.slicedir = slicedir
        self.save_prefix = save_prefix
        self.pool = pool

        # states
        self.skip_first_dividend = skip_first_dividend
        self.today_ = today_
        self.days = days
        self.skip_days = sorted(set(skip_days))
        self.hold = hold.copy()
        self.usable = usable.copy()
        self.target_cash = target_cash_initial
        self.hold_value0 = hold_value_initial
        self.real_cash = real_cash
        print('target_cash = {}, hold_value0 = {}, real_cash = {}'.format(self.target_cash, self.hold_value0, self.real_cash))

        # results
        self.trade_log = pd.DataFrame()
        self.date_list = [self.today_]
        self.pnl_list = [0]
        self.fee_list = [0]
        self.turn_rate_list = [0]
        self.real_cash_list = [real_cash]
        self.latest_slice = pd.DataFrame(columns=['code', 'price']).set_index('code')

        self.hold_num_list = [0]
        self.cash_list = [target_cash_initial]

        if self.days != []:
            while self.skip_days != [] and self.skip_days[0] < self.days[0]:
                self.skip_days = self.skip_days[1:]

        self.sod_call = sod_call

    def step(self, f_finish=None):
        if len(self.days) == 0:
            return None

        ret = None

        today = self.days[0]

        if len(self.date_list) != 1 or (not self.skip_first_dividend):
            handle_dividend(self.hold, today)
            handle_dividend(self.usable, today)

        target_cash_base = self.target_cash - self.hold_value0

        while self.skip_days != [] and self.skip_days[0] == today:
            print('skip {}'.format(today))
            self.skip_days = self.skip_days[1:]
            self.today_ = today
            self.days = self.days[1:]
            if self.days == []:
                return None
            today = self.days[0]
            handle_dividend(self.hold, today)
            handle_dividend(self.usable, today)

        print('simulate %s (yesterday %s)' % (today, self.today_))
        if not (self.sod_call is None):
            data = {}
            data['slicedir'] = self.slicedir
            if 'config_json' in self.config:
                data['config'] = json.loads(self.config['config_json'])
            else:
                data['config'] = {}

            self.sod_call(today, data)

            self.slicedir = data['slicedir']
            self.config['config_json'] = json.dumps(data['config'], ensure_ascii=False).encode()

        if self.pool is None:
            ret = pypinot.sim_one(
                self.config,
                today, self.today_,
                self.hold, self.usable, self.slicedir, target_cash_base, self.real_cash)
        else:
            p = (self.config, today, self.today_, self.hold, self.usable, self.slicedir, target_cash_base, self.real_cash)
            # f_aux NOTE: earlier date has higher priority, hence reduces the latency
            ret = self.pool.map_async(SimStubs2.sim_one, [p], script='/opt/bbcluster/alpha/pinot/SimStubs2.py', f_aux=lambda x: (-1, 21000000-int(today)), f_finish=f_finish)

        return ret

    def step_finish(self, w):
        assert(w != None)

        today = self.days[0]
        hold0 = self.hold

        if type(w) == tuple:
            self.hold, self.usable, thislog, self.latest_slice, self.real_cash = w
        else:
            self.hold, self.usable, thislog, self.latest_slice, self.real_cash = w.wait()[0]

        if len(thislog) != 0:
            thislog['date'] = today
            self.trade_log = pd.concat([self.trade_log, thislog], axis = 0)
            fee = self.trade_log['fee'].sum()
        else:
            fee = self.fee_list[-1]

        pnl = self.pnl_list[-1] - self.hold_value0
        pnl += compute_hold_value(self.latest_slice, hold0)
        if len(thislog) != 0:
            pnl += compute_pnl(self.latest_slice, thislog)

        print('pnl:', pnl, 'len(log)', len(thislog))
        turn_rate = thislog.apply(lambda x: x['price'] * x['volume'], axis = 1).sum() if len(thislog) != 0 else 0
        turn_rate = turn_rate / self.target_cash

        self.fee_list.append(fee)
        self.pnl_list.append(pnl)
        self.date_list.append(today)
        self.turn_rate_list.append(turn_rate)
        self.target_cash = self.target_cash_initial + pnl - fee

        self.hold_value0 = compute_hold_value(self.latest_slice, self.hold)

        self.real_cash_list.append(self.real_cash)

        ####
        self.hold_num_list.append(len(self.hold[self.hold['volume'] >= 1]))
        self.cash_list.append(self.target_cash - self.hold_value0)
        ####

        if self.save_prefix != None:
            fp = open('{}/{}.pkl'.format(save_prefix, today), 'wb')
            pickle.dump((self.target_cash, self.hold_value0, self.hold, self.usable), fp)
            fp.close()

        self.usable = self.hold.copy()
        self.today_ = today
        self.days = self.days[1:]
        pass

    def finish(self):
        df = pd.DataFrame({'date': self.date_list, 'pnl': self.pnl_list, 'fee': self.fee_list, 'turn_rate': self.turn_rate_list,
                           'eod_hold_num': self.hold_num_list, 'eod_cash': self.cash_list, 'eod_real_cash': self.real_cash_list})
        return (self.hold, self.usable, self.trade_log, self.latest_slice, df)
