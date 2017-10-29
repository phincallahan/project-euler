from lib.performance import do_cprofile
from itertools import permutations, islice

@do_cprofile
def solution():
    def num_islice(* args):
        return sum(d * 10 ** i for i, d in enumerate(islice(* args)))

    for perm in permutations(x for x in range(1, 10)):
        x, y = num_islice(perm, 5, 9), num_islice(perm, 5)

        if y % x == 0 and y / x == 2:
            return num_islice(perm, 9)

solution()
