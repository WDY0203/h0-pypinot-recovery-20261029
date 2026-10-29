import sys
import io
import pandas as pd
import numpy as np
from . import util
_pypinot = util.import_so('_pypinot')
#from . import _pypinot

#utils
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
    sys.stderr.flush()

# SecInfo
def getRescale(code, date):
    return _pypinot.getRescale(code + ".CNSHS", int(date))

def getClosePrice(code, date):
    return _pypinot.getClosePrice(code + ".CNSHS", int(date))

def getPreClosePrice(code, date):
    return _pypinot.getPreClosePrice(code + ".CNSHS", int(date))

def getLastClosePrice(code, date):
    return _pypinot.getLastClosePrice(code + ".CNSHS", int(date))

def read_csv_string(s, names, types, index = None):
    dtype = {}
    for i in range(len(names)):
        dtype[names[i]] = types[i]
    r = pd.read_csv(io.StringIO(s), names = names, header = None, dtype = dtype)
    if index != None:
        r.set_index(index, inplace = True)
    return r

#encode, decode
def decode_hold(r):
    assert(r['type'] == 'hold')

    hold = read_csv_string(r['se_hold_csv'], ['code', 'volume'], [str, float], 'code')
    usable = read_csv_string(r['se_usable_csv'], ['code', 'volume'], [str, float], 'code')
    return hold, usable

def decode_trade_log(r):
    assert(r['type'] == 'trade_log')
    trade_log = read_csv_string(r['trade_log_csv'],
                                ['ts', 'order_id', 'type', 'code', 'price0', 'volume0', 'price', 'volume', 'fee'],
                                [str,  int,        str,    str,    float,    float,      float,   float,    float])
    return trade_log

def decode_slice_price(r):
    assert(r['type'] == 'slice' or r['type'] == 'slice_ext')
    slice_price = read_csv_string(r['se_prc_csv'], ['code', 'price'], [str, float], 'code')
    return slice_price

def encode_hold(hold, usable):
    io_hold = io.StringIO()
    io_usable = io.StringIO()
    hold.to_csv(io_hold, header = False)
    usable.to_csv(io_usable, header = False)
    return {'type': 'hold', 'se_hold_csv': io_hold.getvalue(), 'se_usable_csv': io_usable.getvalue()}

def decode_raw_slice(content):
    assert(content['type'] == 'raw_slice')
    if 'binary' in content:
        decoded = _pypinot.pinot_decode_slice_helper(content['binary'])
        buf = np.frombuffer(decoded[1][1], dtype = np.double)
        buf.shape = (len(decoded[1][0]), buf.size // len(decoded[1][0]))
        values = pd.DataFrame(buf, index = map(lambda x: x.decode(), decoded[1][0]))
        values.rename(inplace=True, columns=lambda x: 'price' if x == 0 else 'volume' if x == 1 else x - 2)
        ts = decoded[0].decode()
        content['ts'] = ts #XXX
        return {'ts': ts, 'stream_id': 0, 'values': values} # TODO: support stream_id in binary protocol
    values = pd.read_csv(io.StringIO(content['values_csv']), header = None, converters = {0:str})
    values.rename(inplace=True, columns=lambda x: 'code' if x == 0 else 'price' if x == 1 else 'volume' if x == 2 else x - 3)
    values.set_index('code', inplace=True)
    stream_id = 0
    if 'stream_id' in content:
        stream_id = content['stream_id']
    return {'ts': content['ts'], 'stream_id': stream_id, 'values': values}

def decode_trader_helper_request(content):
    assert(content['type'] == 'trader_helper_request')
    assert('binary' in content)
    if 'binary' in content:
        decoded = _pypinot.pinot_decode_trader_helper_request_helper(content['binary'])
        buf = np.frombuffer(decoded[1][1], dtype = np.double)
        buf.shape = (len(decoded[1][0]), buf.size // len(decoded[1][0]))
        values = pd.DataFrame(buf, index = map(lambda x: x.decode(), decoded[1][0]))
        values.rename(inplace=True, columns=lambda x:
                      'hold' if x == 0 else
                      'usable' if x == 1 else
                      'price' if x == 2 else
                      'volume' if x == 3 else x - 4)
        ts = decoded[0].decode()
        content['ts'] = ts #XXX
        return {'ts': ts, 'values': values}


def update_slice(raw_slice, f):
    new_slice = {}
    new_slice['ts'] = raw_slice['ts']
    new_slice['price'] = raw_slice['values']['price']
    new_slice['volume'] = raw_slice['values']['volume']
    a = f(raw_slice)
    if isinstance(a, pd.Series):
        # to be removed
        new_slice['alpha'] = a
    else:
        new_slice['alphas'] = a
    return new_slice

def encode_slice(o):
    if 'alpha' in o:
        # to be removed
        io_price = io.StringIO()
        io_volume = io.StringIO()
        io_alpha = io.StringIO()
        o['price'].to_csv(io_price, header = False)
        o['volume'].to_csv(io_volume, header = False)
        o['alpha'].to_csv(io_alpha, header = False)
        return {'type': 'slice', 'ts': o['ts'],
                'se_prc_csv': io_price.getvalue(),
                'se_volume_csv': io_volume.getvalue(),
                'se_alpha_csv': io_alpha.getvalue()}
    else:
        return {'type': 'slice_ext', 'ts': o['ts'],
                'se_prc_csv': o['price'].to_csv(header = False),
                'se_volume_csv': o['volume'].to_csv(header = False),
                'se_alphas_csv': o['alphas'].to_csv(header = False)}

def encode_ap(o):
    io_price = io.StringIO()
    o['values'].to_csv(io_price, header = False)
    return {'type': 'slice', 'ts': o['ts'],
            'se_prc_csv': io_price.getvalue(),
            'se_volume_csv': '',
            'se_alpha_csv': ''}

def encode_slice_end():
    return {'type': 'slice_end'}

def encode_ap_end():
    return encode_slice_end()

# sim_one
import socket
import subprocess
import signal
import os, sys
from external import transport
from external.transport import Transport

def _set_pdeathsig(sig=15):
    import ctypes
    def callable():
        libc = ctypes.CDLL("libc.so.6")
        return libc.prctl(1, sig)
    return callable

'''
#tcp version
def open_socket():
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    s.bind(('127.0.0.1', 0))
    s.listen(511)
    return s

def spawn_bus(cwd, n):
    s = open_socket()
    port = s.getsockname()[1]
    fd = s.fileno()
    bus = subprocess.Popen(['./Bus', '-d', str(fd), '-n', str(n)], cwd=cwd, preexec_fn=_set_pdeathsig(), pass_fds={fd})
    s.close()
    return (bus, '127.0.0.1', port)
'''

# unix version
def open_socket(name):
    s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    s.bind(name)
    s.listen(511)
    return s

def spawn_bus(cwd, n, bus_name = None, args = []):
    if bus_name == None:
        bus_name = str(os.getpid())

    if 'create' in dir(transport.bbws):
        shm_file = '/dev/shm/pinot-bus-' + bus_name + '.shm'
        transport.bbws.create(shm_file)
        return (None, shm_file, 65535)

    socket_file = '/dev/shm/pinot-bus-' + bus_name + '.unix'
    try:
        os.remove(socket_file)
    except:
        pass
    s = open_socket(socket_file)
    fd = s.fileno()
    bus = subprocess.Popen(['./Bus', '-d', str(fd), '-n', str(n)] + args, cwd=cwd, preexec_fn=_set_pdeathsig(), pass_fds={fd})
    s.close()
    return (bus, socket_file, 65535)

def spawn_x(cwd, args, env, input_string):
    xenv = os.environ.copy()
    if env != None:
        xenv.update(env)
    input_obj = None
    if input_string != None:
        input_obj = subprocess.PIPE
    p = subprocess.Popen(args, cwd=cwd, preexec_fn=_set_pdeathsig(), env=xenv, stdin=input_obj, pass_fds={})
    if input_string != None:
        p.stdin.write(input_string)
        p.stdin.close()
    return p

def interp_args(config, args):
    new_args = []
    for a in args:
        if type(a) == str:
            new_args.append(a)
        elif type(a) == list and len(a) == 1:
            if config[a[0]] != None:
                new_args.append(str(config[a[0]]))
        else:
            raise Exception("bad config")
    return new_args

def interp_env(config, env):
    new_env = {}
    for (k, v) in env.items():
        if type(v) == str:
            new_env[k] = v
        elif type(a) == list and len(a) == 1:
            new_env[k] = str(config[a[0]])
        else:
            raise Exception("bad config")
    return new_env

def sim_one(t_config, today, today_, hold, usable, slicedir, target_cash_base, real_cash = 0.0):
    config = t_config.copy()
    config['today'] = today
    config['today_'] = today_
    config['target_cash_base'] = '{},{}'.format(target_cash_base, real_cash);

    if not ('project_dir' in config):
        config['project_dir'] = os.path.dirname(sys.argv[0])

    if slicedir != None:
        if slicedir != '':
            if slicedir[:6] == 'gds://':
                config['slice_file'] = slicedir
            else:
                config['slice_file'] = slicedir + '/' + today
        else:
            config['slice_file'] = ''
        idx = 1 # XXX
        config['components'][idx]['args'] = config['components'][idx]['args2']

    components = {}
    n = 1  # myself
    for c in config['components']:
        if ('use_bus' in c) and c['use_bus']:
            n = n + 1
    bus, addr, port = spawn_bus(os.path.join(config['project_dir'], 'external/bus'),
                                n,
                                bus_name = config['bus_name'] if ('bus_name' in config) else None,
                                args = config['bus_args'] if ('bus_args' in config) else [])
    eprint('bus(%d) listen on %s:%d' % (bus.pid if bus != None else 0, addr, port))
    config['addr'] = addr
    config['port'] = port
    if bus != None:
        components['bus'] = bus

    tp = Transport('main', addr = config['addr'], port = config['port'])

    tp.send('trader', encode_hold(hold, usable))

    for conf in config['components']:
        env = None
        if 'env' in conf:
            env = interp_env(config, conf['env'])
        args = interp_args(config, conf['args'])
        input_string = None
        if 'input_field' in conf:
            input_string = config[conf['input_field']]
        components[conf['name']] = spawn_x(config['project_dir'], args, env, input_string)

    ret = 0
    signal.signal(signal.SIGCHLD, lambda signo, frame: None)
    signal.signal(signal.SIGINT, lambda signo, frame: os.remove(config['addr']) if config['addr'][0] == '/' else None)
    while True:
        signal.pause()
        for (name, comp) in components.items():
            ret = comp.poll()
            if ret != None:
                eprint('%s exit with %d' % (name, ret))
                if config['addr'][0] == '/':
                    os.remove(config['addr'])

                result = (1, None, None)
                if name == 'simulator' and ret == 0:
                    while result[0] == 1:
                        result = tp.recv()
                tp.close()

                for (kn, kc) in components.items():
                    if kn != name:
                        eprint('killing %s' % kn)
                        kc.terminate()
                res = result[2]
                hold, usable = decode_hold(res['hold'])
                trade_log = decode_trade_log(res['trade_log'])
                slice_price = decode_slice_price(res['slice'])
                real_cash = 0.0
                if 'real_cash' in res:
                    real_cash = res['real_cash']
                return (hold, usable, trade_log, slice_price, real_cash)
