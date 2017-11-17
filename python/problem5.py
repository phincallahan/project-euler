from lib.factorization import factor_method

def solution():
    factor = factor_method([2, 3, 5, 7, 11, 13, 17, 19])
    factorization = factor(1)
    for num in range(2, 21):
        factorization |= factor(num)

    return int(factorization)
