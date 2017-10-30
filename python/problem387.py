from lib.primes import isPrime
from lib.performance import do_cprofile

@do_cprofile
def solution():
    harshad = [(i, i) for i in range(1, 10)]
    result = 0

    for j in range(13):
        nHarshad = []
        for x, s in harshad:
            nHarshad.append((x * 10, s))
            xIsPrime = isPrime(x // s)
            for i in range(1, 10):
                if not (10 * x + i) % (s + i):
                    nHarshad.append(((10 * x + i), s + i))
                if xIsPrime and isPrime(10 * x + i):
                    result += 10 * x + i
            
        harshad = nHarshad

    return result

solution()
