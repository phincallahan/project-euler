from itertools import permutations, islice


def take_digits(perm, i, j = 0):
    if j > 0:
        return int(''.join(perm[i:j]))
    else:
        return int(''.join(perm[:i]))

i = 0
digits = [str(x) for x in reversed(range(1, 10))]
for perm in permutations(digits):
    x = take_digits(perm, 4)
    y = take_digits(perm, 4, 9)

    if y % x == 0 and y / x == 2:
        print(take_digits(perm, 9))
        break