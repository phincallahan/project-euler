from lib.pythagorean import primitive_triplets
from lib.performance import do_cprofile
from collections import Counter

@do_cprofile
def solution():
    c = Counter()
    triplet_gen = primitive_triplets(lambda t: sum(t) <= 1000)
    for t in triplet_gen:
        c.update(sum(t) * k for k in range(1, 1000 // sum(t) + 1))

    return c.most_common(1)[0][0]

solution()
