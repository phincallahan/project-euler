from pyprimesieve import primes as get_primes

PRIMES = get_primes(10 ** 4)
def isPrime(x):
    for prime in PRIMES:
        if x % prime == 0:
            return False
        elif prime * prime > x:
            return True

    prime = PRIMES[-1]
    while prime * prime < x:
        prime += 1
        if x % prime == 0:
            return False

    return True

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

print(sum(trunc))
