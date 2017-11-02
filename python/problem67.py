from lib.utils import read_triangle
from problem18 import triangle_sum

def solution():
    tri = read_triangle('../assets/p067_triangle.txt')
    return triangle_sum(tri)

