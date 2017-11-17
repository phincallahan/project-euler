from functools import reduce

def solution():
    digits = list(map(int, open('../assets/p008_number.txt').read()))
    digit_slices = zip(*[digits[i:] for i in range(13)])
    return max(reduce(int.__mul__, d_slice) for d_slice in digit_slices)
