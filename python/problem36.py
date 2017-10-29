from lib.performance import do_cprofile
from lib.palindrome import isPalindrome
from lib.permutations import binary_permutations

@do_cprofile
def solution1():
    cond = lambda i: isPalindrome(i) and isPalindrome(bin(i)[2:])
    return sum(i for i in range(10 ** 6) if cond(i))

@do_cprofile
def solution2():
    palindrome_sum = 0
    for perm in binary_permutations(10):
        palindromes = (perm[::-1] + c + perm for c in ['0', '1', ''])
        ints = [int(p, 2) for p in palindromes if int(p, 2) < 10 ** 6]
        if not ints: 
            return(palindrome_sum)

        palindrome_sum += sum(i for i in ints if isPalindrome(i))

    return(palindrome_sum)

solution2()
