from lib.primes import prime_sieve
from math import sqrt

def solution1():
    MAX_VALUE = 10 ** 11
    q_primes, p_primes = [], []
    for p in prime_sieve(5000000):
        if p % 4 == 1:
            q_primes.append(p)
        else:
            p_primes.append(p)

    total = 0
    def count(x, start = 0):
        global total
        total += x
        for i in range(start, len(p_primes)):
            if p_primes[i] * x < MAX_VALUE:
                count(p_primes[i] * x, i)
            else:
                break

    for a in q_primes:
        if a ** 3 > MAX_VALUE: break
        for b in q_primes:
            if b == a: continue
            if a ** 3 * b ** 2 > MAX_VALUE: break
            for c in q_primes:
                if c == a or c == b: continue
                if a ** 3 * b ** 2 * c > MAX_VALUE: break
                count(a ** 3 * b ** 2 * c)

    for a in q_primes:
        if a ** 10 > MAX_VALUE:
            break
        for b in q_primes:
            if b == a: continue
            if a ** 10 * b ** 2 > MAX_VALUE:
                break
            count(a ** 10 * b ** 2)

    for a in q_primes:
        if a ** 7 > MAX_VALUE: break
        for b in q_primes:
            if b == a: continue
            if a ** 7 * b ** 3 > MAX_VALUE: break
            count(a ** 7 * b ** 3)
    
    return total
