def solution():
    names = open('../assets/p022_names.txt').read()[1:-1]
    names = sorted(names.split('","'))
    names = (sum(map(ord, n)) - 64 * len(n) for n in names)
    return sum((i + 1) * n for i, n in names)
