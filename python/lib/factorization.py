from functools import reduce
from collections import Counter

from lib.primes import prime_sieve

class Factorization(Counter):
    def __init__(self, factors={}):
        Counter.__init__(self, factors)

    def __int__(self):
        powers = [y ** n for y, n in self.items()]
        return reduce(int.__mul__, powers, 1)

    def __and__(self, other):
        return Factorization(Counter.__and__(self, other))

    def __or__(self, other):
        return Factorization(Counter.__or__(self, other))

    def __add__(self, other):
        return Factorization(Counter.__add__(self, other))

def factor_method(primes = None, cache = {}, N = 10 ** 4):
    if primes is None:
        primes = list(prime_sieve(N))

    for p in primes:
        cache[p] = Factorization({p : 1})
        for q in primes:
            if p == q:
                cache[p * q] = Factorization({p : 2})
            else:
                cache[p * q] = Factorization({p : 1, q: 1})
    
    def factor(n, prime_it=None):
        if n == 1:
            return Factorization()
        if n in cache:
            return cache[n].copy()
        if prime_it is None:
            prime_it = iter(primes)

        try:
            prime = next(p for p in prime_it if n % p == 0)
        except StopIteration:
            if N * N > n:
                return Factorization({n: 1})
            else:
                raise Exception("Not enough primes to factor!")

        c = 0
        while not n % prime:
            n //= prime
            c += 1

        return factor(n, prime_it) + Factorization({prime: c})

    return factor

def divisors(prf):
    div = [1]
    for prime, k in prf.items():
        div = [d * prime ** j for d in div for j in range(k + 1)]

    return div

def totient(prf):
    den = reduce(lambda d, k: d * k, prf, 1)
    num = reduce(lambda d, k: d * (k - 1), prf, 1)
    return int(prf) * num // den

def prime_factors(prf):
    return prf.elements()

def distinct_prime_factors(prf):
    return prf.keys()

def gcd(a, b):
    return int(a & b)

def lcm(a, b):
    return int(a | b)

def coprime(prf):
    N = prf(int)
    copr = set(range(N))
    for factor in distinct_prime_factors(prf):
        copr -= set(factor * i for i in range(N // factor))

    return copr

def proper_divisors(prf):
    return divisors(prf)[:-1]

def aliquotSum(prf):
    return sum(proper_divisors(prf))

def isAbundant(n, factor):
    return aliquotSum(factor(n)) > n

def isDeficient(n, factor):
    return aliquotSum(factor(n)) < n

def isPerfect(n, factor):
    return aliquotSum(factor(n)) == n

def order(a, p, x = 1):
    seen = set([x])
    for i in range(p):
        x = (x * a) % p
        if x == 1:
            return i + 1
        if x == -1:
            return 2 * (i + 1)
        if x in seen:
            return 0
        else: seen.add(x)

def primitive_roots(n):
    phi = totient(n)
    return [k for k in range(1, n) if order(k, n) == phi]
