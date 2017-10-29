from lib.performance import do_cprofile
from collections import defaultdict

@do_cprofile
def solution():
    def hasUniqueDigits(x):
        a, b, c = (x % 10, x // 10 % 10, x // 100 % 100)
        return a != b != c != a 

    def toNumber(digits):
        x = sum(d * 10 ** i for i, d in enumerate(reversed(digits)))
        return (sum(range(10)) - sum(digits)) * 10 ** 9 + x

    def toDigits(number):
        digits = [int(d) for d in str(number)] 
        return digits if len(digits) == 3 else [0] + digits

    hts = {i: defaultdict(list) for i in range(6)}
    for i, p in enumerate([3, 5, 7, 11, 13, 17]):
        for n in (p * (k + 1) for k in range(10 // p, 1000 // p)):
            hts[i][n // 10].append(n % 10)

    def findNumber(curr, i = 0):
        if i == 6: return toNumber(curr) 

        k = 10 * curr[-2] + curr[-1]
        vs = (v for v in hts[i][k] if v not in curr)
        return sum(findNumber(curr + [v], i + 1) for v in vs)

    start = [toDigits(x) for x in range(12, 499, 2) if hasUniqueDigits(x)]
    return sum(findNumber(s) for s in start)

solution()
