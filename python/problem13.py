def solution():
    numbers = open('../assets/p013_numbers.txt').readlines()
    return str(sum(int(n) for n in numbers))[0:10]
