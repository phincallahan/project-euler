from lib.utils import read_triangle

def triangle_sum(tri):
    for i in range(len(tri) - 1, 0, -1):
        for j in range(i):
            tri[i - 1][j] += max(tri[i][j], tri[i][j + 1])

    return tri[0][0]

def solution():
    tri = read_triangle('../assets/p018_triangle.txt')
    return triangle_sum(tri)
