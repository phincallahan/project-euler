from lib.factorization import factor_method, divisors
from itertools import accumulate, count

def solution():
    factor = factor_method(N=10 ** 3)
    for triangle in accumulate(count(1)):
        try:
            prf = factor(triangle)
            if len(divisors(prf)) > 500:
                return triangle
        except StopIteration:
            continue
