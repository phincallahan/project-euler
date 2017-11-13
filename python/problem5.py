from lib.factorization import factor
from lib.primes import prime_sieve

def solution():
    primes = [2, 3, 5, 7, 11, 13, 17, 19]
    f = factor(1, primes)
    for n in range(2, 21):
        f |= factor(n, primes)

    return int(f)