from lib.factorization import factor_method, aliquotSum

def solution(N = 10 ** 4):
    factor = factor_method(N = int(10 ** 3))
    s = 0
    for n in range(1, N):
        d = aliquotSum(factor(n))
        if d > n and n == aliquotSum(factor(d)):
            s += n + d if d < N else 0

    return s

print(solution())