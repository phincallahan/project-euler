from lib.pythagorean import primitive_triplets

def solution():
    for a, b, c in primitive_triplets(lambda x: sum(x) <= 1000):
        if 1000 % (a + b + c) == 0:
            return a * b * c * (1000 // (a + b + c)) ** 3
