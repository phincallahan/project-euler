from lib.performance import do_cprofile
from io import open

@do_cprofile
def solution():
    with open('../assets/p042_words.txt') as f:
        count = 0
        tri_num = set(n * (n + 1) // 2 for n in range(1000))
        for word in f.read().split(','):
            count += sum(ord(l) - 64 for l in word[1:-1]) in tri_num
        return count

solution()
