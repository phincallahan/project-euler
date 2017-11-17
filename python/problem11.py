from lib.utils import read_matrix
from itertools import chain
from functools import reduce

def diag(m, N):
    for j in range(len(m) - N + 1):
        yield from zip(*[m[j + i][i:] for i in range(N)])
        yield from zip(*[m[j - i + N - 1][i:] for i in range(N)])

def horz(m, N):
    for j in range(len(m)):
        yield from zip(*[m[j][i:] for i in range(N)])

def vert(m, N):
    for j in range(len(m) - N + 1):
        yield from zip(*[m[j + i] for i in range(N)])

def solution():
    matrix = read_matrix('../assets/p011_matrix.txt', ' ')
    slices = chain(diag(matrix, 4), vert(matrix, 4), horz(matrix, 4))
    return max(reduce(int.__mul__, s) for s in slices)
