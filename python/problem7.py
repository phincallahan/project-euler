from lib.primes import prime_sieve

def solution():
    primes = prime_sieve(10 ** 6)
    return next(p for i, p in enumerate(primes) if i == 10 ** 4 + 1)

print(solution())