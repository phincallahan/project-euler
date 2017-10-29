from lib.primes import miller_rabin
from lib.performance import do_cprofile

@do_cprofile
def solution():
    harshad = [(i, i) for i in range(1, 10)]
    result = 0

    for j in range(13):
        nHarshad = []
        for x, s in harshad:
            nHarshad.append((x * 10, s))
            xIsPrime = miller_rabin(x // s)
            for i in range(1, 10):
                if not (10 * x + i) % (s + i):
                    nHarshad.append(((10 * x + i), s + i))
                if xIsPrime and miller_rabin(10 * x + i):
                    result += 10 * x + i
            
        harshad = nHarshad

    return result

solution()
