from lib.primes import prime_sieve
from lib.factorization import factor

def solution():
    factorization = factor(600851475143, prime_sieve(10000))
    return max(k for k in factorization)