import os
from datetime import date
startyear = 2010
endyear = 2022

#endyear = date.today().year
#if endyear < 2021:
#    endyear = 2021

prefix = '/opt/autotrade'
if 'TRADING_PATH' in os.environ:
    prefix = os.environ['TRADING_PATH']

closedays = set()
for year in range(startyear, endyear + 1):
    stryear = str(year)
    l = open('{}/Symbols/closeday_{}.csv'.format(prefix, stryear)).read().strip().split(',')
    l = map(lambda x: '{}{}'.format(stryear, x), l)
    closedays.update(l)

#print(sorted(closedays))

closedays = set(map(lambda x: date(int(x[0:4]), int(x[4:6]), int(x[6:8])).toordinal(), closedays))

dates2 = filter(lambda x: x.isoweekday() <= 5,
                map(lambda x: date.fromordinal(x),
                    filter(lambda x: not (x in closedays),
                           range(date(startyear, 1, 1).toordinal(), date(endyear, 12, 31).toordinal() + 1))))
dates2 = list(map(lambda x: x.strftime('%Y%m%d'), dates2))
for line in dates2:
    print(line)
