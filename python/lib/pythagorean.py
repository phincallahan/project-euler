import numpy as np
from collections import deque

def primitive_triplets(fltr = lambda x: True):
    M = np.array([
        [ 1, -2, 2], 
        [ 2, -1, 2], 
        [ 2, -2, 3],
        [ 1,  2, 2], 
        [ 2,  1, 2], 
        [ 2,  2, 3],
        [-1,  2, 2], 
        [-2,  1, 2], 
        [-2,  2, 3]
    ])

    dq = deque([np.array([3, 4, 5])])
    while len(dq):
        new_triplets = M.dot(dq[0]).reshape((3,3))
        dq.extend(x for x in new_triplets if fltr(x))
        yield dq.popleft()
