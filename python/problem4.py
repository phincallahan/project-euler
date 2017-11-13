from lib.palindrome import isPalindrome

def solution():
    m = 10 * 8
    for i in range(999, 99, -1):
        if i ** 2 < m: return m
        for j in range(i, 99, -1):
            if isPalindrome(j * i) and i * j > m:
                m = i * j 