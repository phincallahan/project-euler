from itertools import count, takewhile
from lib.performance import do_cprofile

@do_cprofile
def solution1():
    triangles   = (n * (n + 1) // 2 for n in count(143))
    pentagonals = (n * (3 * n - 1) // 2 for n in count(165))
    hexagonals  = (n * (2 * n - 1) for n in count(285))

    for h in hexagonals:
        for p in takewhile(lambda x: x <= h, pentagonals): 
            for t in takewhile(lambda x: x <= p, triangles): 
                if p == t == h: return t

solution1()
