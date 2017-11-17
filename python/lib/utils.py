def cached(n):
    def wrapper(func):
        def inner_wrapper(* args, ** kwargs):
            if args[0] not in cache:
                cache[args[0]] = func(*args, **kwargs)

            return cache[args[0]].copy()
        return inner_wrapper

    cache, func = ({}, n) if callable(n) else (n, None)
    return wrapper(func) if callable(n) else wrapper

def read_matrix(path, delimeter = ','):
    with open(path, 'r') as f:
        return [[int(x) for x in line.split(delimeter)] for line in f]

def read_triangle(path):
    return read_matrix(path, ' ')
