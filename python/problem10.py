from lib.primes import prime_sieve, miller_rabin

def solution():
    return sum(prime_sieve(2 * (10 ** 6)))
