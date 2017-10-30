from lib.performance import do_cprofile

@do_cprofile
def solution():
    digits = [1] + [0] * 9 
    for i in range(1, 10):
        digits[i] = 9 * i * 10 ** (i - 1) + digits[i - 1]

    def nth_digit(n):
        for i in range(1, 10):
            if digits[i] >= n:
                break
        
        n = n - digits[i - 1]
        return int(str(10 ** (i - 1) +  n // i)[n % i])

    result = 1
    for i in range(7):
        result *= nth_digit(10 ** i)

    return result

solution()
