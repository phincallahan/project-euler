from itertools import count, takewhile
from lib.factorization import factor_method

def solution(N = 600851475143):
    for i in takewhile(lambda _: N > 1, count(2)):
        while N % i == 0: N //= i
    return i

print(solution())