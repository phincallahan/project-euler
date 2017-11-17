from bisect import bisect_left 
from itertools import count, chain
from random import sample

def prime_sieve(n):
    mask = [False] + [True] * (n - 1)
    i = 2
    while i * i <= n:
        yield i
        for j in range(2 * i, n + 1, i):
            mask[j - 1] = False

        while mask[i] == False and i * i < n:
            i += 1
        i += 1

    yield from (j + 1 for j in range(i, n) if mask[j])

def trial_division(n, primes):
    if n == 0: return (0, 0)
    if n == 1: return (1, 1)
    if n <= primes[-1]:
        i = bisect_left(primes, n)
        return i < len(primes) and primes[i] == n
    else:
        for p in chain(primes, count(primes[-1], 2)):
            if n % p == 0:
                return (n // p, p)
            if p * p > n:
                return (n, 1)

def miller_rabin(n, k = 10):
    if n < 2:
        return False
    if n == 2 or n == 3:
        return True
    if not n & 1:
        return False

    def check(a, s, d, n):
        x = pow(a, d, n)
        if x == 1:
            return True
        for i in range(s - 1):
            if x == n - 1:
                return True
            x = pow(x, 2, n)
        return x == n - 1
    
    s, d = 0, n - 1
    while d % 2 == 0:
        d >>= 1
        s += 1

    if n < 2047:
        a = [2]
    elif n < 1373653:
        a = [2, 3]
    elif n < 9080191:
        a = [31, 73]
    elif n < 25326001:
        a = [2, 3, 5]
    elif n < 3215031751:
        a = [2, 3, 5, 7]
    elif n < 4759123141:
        a = [2, 7, 61]
    elif n < 1122004669633:
        a = [2, 13, 23, 1662803]
    elif n < 2152302898747:
        a = [2, 3, 5, 7, 11]
    elif n < 3474749660383:
        a = [2, 3, 5, 7, 11, 13]
    elif n < 341550071728321:
        a = [2, 3, 5, 7, 11, 13, 17]
    else:
        a = sample(range(2, n), k)

    return all(check(x, s, d, n) for x in a)

class PrimeList(list):
    class Iter:
        def __init__(self, primes, inner_iter = None):
            self.__prime_list = primes
            if inner_iter is None:
                self.__inner_iter = list.__iter__(primes)
            else:
                self.__inner_iter = inner_iter.__iter__()

        def __iter__(self):
            return PrimeList.Iter(self.primes, self.__inner_iter)

        def __next__(self):
            try:
                return next(self.__inner_iter)
            except StopIteration:
                self.__prime_list.grow()
                return next(self)

    def __init__(self, n = 1000):
        list.__init__(self, prime_sieve(n))

    def __in__(self, n):
        i = bisect_left(self, n)
        return i < len(self) and self[i] == n

    def __iter__(self):
        return PrimeList.Iter(self)

    def check(self, n):
        if n <= self.primes[-1]:
            return n in self
        else:
            for p in self:
                if n % p == 0:
                    return False
            return True

    def grow(self, n = None):
        n = n if n is not None else self[-1] * 10
        self.extend(Primes.sieve(n, self.max))
