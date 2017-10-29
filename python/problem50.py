from lib.performance import do_cprofile
from lib.primes import prime_sieve, isPrime
from itertools import count, accumulate

@do_cprofile
def solution():
    primes = prime_sieve(10 ** 4)

    N = 10 ** 6
    for max_i, p_sum in enumerate(accumulate(primes)):
        if p_sum >= N: break

    for i in range(max_i, 0, -1):
        p_sum = sum(primes[0:i])
        for j in count():
            if p_sum >= N:
                break
            if isPrime(p_sum):
                return p_sum
            else:
                p_sum = p_sum + primes[i + j] - primes[j]


solution()
