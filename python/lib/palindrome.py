def isPalindrome(pal):
    if type(pal) == int: 
        pal = str(pal)

    return pal == pal[::-1]
