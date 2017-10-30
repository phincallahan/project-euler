from lib.performance import do_cprofile
from itertools import accumulate, combinations_with_replacement
from collections import deque

@do_cprofile
def solution():
    factorial = [1, *accumulate(range(1, 10), int.__mul__)]

    def digits(n):
        dig = [0] * 10
        for d in str(n):
            dig[int(d)] += 1
        return dig
    
    def recurse(k = [0] * 10, i = 0, f = 0, d = 0):
        if d == 7: return 0

        s = f if digits(f) == k else 0

        for j in range(i, 10):
            k[j] += 1
            s += recurse(k, j, f + factorial[j], d + 1)
            k[j] -= 1

        return s

    return recurse() - 3

solution()
