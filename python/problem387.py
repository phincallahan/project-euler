from collections import deque
from math import sqrt, ceil

N = 10 ** 14

def sieve(n):
    isPrime = [True for _ in range(n)]
    for i in range(2, int(sqrt(n)) + 1):
        j = 2
        while i * j <= n:
            isPrime[i * j - 1] = False
            j += 1

    return [i + 1 for i in range(1, n) if isPrime[i]]

primes = sieve(1000000)

def sum_dig(x):
    return sum([int(d) for d in str(x)])

def isHarshad(x):
    return x % sum_dig(x) == 0

def isPrime(x):
    if x == 1: return False
    for p in primes:
        if p > sqrt(x):
            return True
        if x % p == 0:
            return False

    for i in range(primes[-1], int(sqrt(x)) + 1):
        if x % i == 0:
            return False

    return True

seeds = [i for i in range(1, 9)]
harshad = deque(seeds)
visited = set()
found = set()

while len(harshad):
    x = harshad.popleft()
    visited.add(x)

    if x * 10 > N:
        continue

    shifted = [ 10 * x + i for i in range(0, 10)]
    for s in shifted:
        if s <= N and isHarshad(s) and s not in visited:
            harshad.append(s)

    if isPrime(x / sum_dig(x)):
        print(shifted)
        for s in shifted:
            if s <= N and isPrime(s):
                found.add(s)

print(sum(found))