from lib.performance import do_cprofile
from itertools import count
from math import sqrt

@do_cprofile
def solution():
    def isPentagonal(n):
        return ((sqrt(1 + 24 * n) + 1) / 6) % 1 == 0

    pentagonals = set()
    for n in (i * (3 * i - 1) // 2 for i in count(1)):
        for m in pentagonals:
            if n - m in pentagonals and isPentagonal(m + n):
                return n - m

        pentagonals.add(n)

solution()
