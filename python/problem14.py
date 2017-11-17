from itertools import takewhile, count

def solution():
    cache = {1: 1}
    def collatz_length(n):
        if n not in cache:
            next_n = 3 * n + 1 if n % 2 > 0 else n // 2
            cache[n] = 1 + collatz_length(next_n)
        
        return cache[n]

    lengths = enumerate(map(collatz_length, range(1, 10 ** 6)))
    return max(lengths, key=lambda x: x[1])[0]

print(solution())