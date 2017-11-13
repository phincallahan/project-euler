from itertools import takewhile

def fib():
    prev, curr = 1, 1
    while True:
        yield curr
        t, curr = curr, curr + prev
        prev = t

def solution():
    bounded_fib = takewhile(lambda x: x < 4 * 10 ** 6, fib()) 
    return sum(x for x in bounded_fib if x % 2 == 0)