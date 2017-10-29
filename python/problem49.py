from lib.performance import do_cprofile
from lib.primes import prime_sieve
from collections import defaultdict
from itertools import combinations

@do_cprofile
def solution():
    primes = [p for p in prime_sieve(10000) if p > 1000]
    prime_map = defaultdict(list)
    for p in primes:
        prime_map[tuple(sorted(str(p)))].append(p)

    for v in prime_map.values():
        for c in combinations(v, 3):
            if c[1] - c[0] == c[2] - c[1] and c[0] != 1487:
                return ''.join(str(x) for x in c)

solution()
