import numpy as np
from collections import defaultdict

def isPythagoreanTriplet(x):
    return x[0] * x[0] + x[1] * x[1] - x[2] * x[2] == 0

def pythag_triples():
    A = np.array(
        [[ 1, -2, 2], [ 2, -1, 2], [ 2, -2, 3],
         [ 1,  2, 2], [ 2,  1, 2], [ 2,  2, 3],
         [-1,  2, 2], [-2,  1, 2], [-2,  2, 3]]
    )

    queue = [np.array([3, 4, 5])]
    while len(queue):
        x = queue.pop()
        if sum(x) < 1000:
            y = np.copy(x)
            while sum(y) < 1000:
                if isPythagoreanTriplet(y):
                    yield y
                y += x

            queue.extend(A.dot(x).reshape((3,3)))

count = defaultdict(int)
m = (0, 0)
for x in pythag_triples():
    count[sum(x)] += 1
    if count[sum(x)] > m[0]:
        m = (count[sum(x)], sum(x))

print(m)