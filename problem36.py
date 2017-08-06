def isPalindrome(s):
    if type(s) == int:
        s = str(s)

    for i in range(len(s) // 2):
        if s[i] != s[len(s) - 1 - i]:
            return False
    
    return True

s = 0
for i in range(10 ** 6):
    if isPalindrome(i) and isPalindrome(bin(i)[2:]):
        s += i

print(s)