from itertools import islice

def pascals(n):
    if n > 1:
        prev = 0
        for p in pascals(n - 1):
            yield prev + p
            prev = p
    yield 1

def solution(N = 20):
    return next(islice(pascals(2 * N + 1), N - 1, N))

print(solution())
