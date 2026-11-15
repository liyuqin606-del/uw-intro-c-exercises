import math
import pathlib
import subprocess

ROOT = pathlib.Path(__file__).resolve().parents[1]

def run(week, exercise, data=''):
    return subprocess.run([str(ROOT / 'build' / f'week{week}'), str(exercise)],
                          input=data, text=True, capture_output=True, check=True).stdout

assert run(1, 1) == 'Hello, world!\n'
assert run(1, 2).splitlines() == ['0 2 4 6 8 ', '100 93 86 79 72 65 58 51 44 37 30 23 16 9 2 ', '1 2 3 4 5 6 7 8 9 10 ', '2 4 8 16 32 64 ']
assert run(1, 3).splitlines()[-1] == '10\t100'
assert run(1, 4).splitlines() == ['*' * n for n in range(1, 11)]
assert run(2, 1) == '7\n'
assert run(2, 2) == '38.5\n'
assert run(2, 3).splitlines()[-1] == '10 is even'
for inp, out in [('1 1','NorthEast'), ('0 -2','South'), ('0 0','stationary'), ('-1 0','West')]: assert run(2, 4, inp).strip() == out
assert run(2, 5).splitlines()[-1] == '7 5040'
assert run(2, 6).strip() == '1 1 2 3 5 8 13 21 34 55'
assert list(map(int,run(2, 7).split())) == [n for n in range(2, 101) if all(n % d for d in range(2,n))]
assert run(3, 1).strip() == '21'
assert run(3, 2).splitlines()[-1] == '10 20'
assert run(3, 3).splitlines()[-1] == '10 100'
assert run(3, 4) == run(1, 4)
assert run(3, 5).splitlines()[-1] == '10 3628800'
assert run(3, 6).splitlines()[0] == '-40 -40.00'
assert run(3, 6).splitlines()[-1] == '220 104.44'
mean, sd = [float(x.split(': ')[1]) for x in run(3,7).splitlines()]
assert 2 <= mean <= 12 and 0 < sd < 6
assert all(1 <= int(n) <= 6 for n in run(3,8).split())
assert sum(int(line.split(': ')[1].split()[0]) for line in run(3,9).splitlines()) == 1000
assert run(4,1,'abc\nZ') == 'abc\nZ'
assert run(4,2,'first\n\nlast') == 'You typed: first\nYou typed: \nYou typed: last\n'
assert run(4,3,'first\n\nlast') == 'first\n\nlast\n'
assert run(4,4,'ab') == "you typed 'a'\nyou typed 'b'\n"
assert run(4,5,'1\n2\n3\n') == 'average: 2.00\nsample standard deviation: 1.00\n'
assert run(4,6,'deposit\n100\ncheck\n12.34\ncheck\n49\ndeposit\n7.01\n') == 'balance: 100.00\nbalance: 87.66\nbalance: 38.66\nbalance: 45.67\n'
assert run(4,7,'-1 1') == 'northwest\n'
assert run(4,8,'A') == 'A 65\n'
assert run(4,9,'abc\n\nxyz') == 'cba\n\nzyx\n'
assert len(run(4,9,'x'*300).strip()) == 255
print('PASS: exercises 1–4, 1–7, 1–9 and 1–9, with edge cases')
