from lib.performance import do_cprofile
from lib.primes import isPrime

@do_cprofile
def solution():
    rq = set([2, 3, 7, 5])
    lq = set([2, 3, 7, 5])
    trunc = set()

    while len(trunc) < 11:
        r_temp = set()
        l_temp = set()

        for s in [1, 2, 3, 5, 7, 9]:
            for rt in rq:
                new_rt = (10 ** len(str(rt))) * s + rt
                if isPrime(new_rt):
                    r_temp.add(new_rt)

            for lt in lq:
                new_lt = 10 * lt + s
                if isPrime(new_lt):
                    l_temp.add(new_lt)
        
        rq = r_temp
        lq = l_temp
        trunc = trunc | (rq & lq)

    return sum(trunc)

solution()
