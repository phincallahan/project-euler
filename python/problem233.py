from lib.primes import prime_sieve

def solution(N = 10 ** 11):
    q_primes, p_primes = [], []
    for p in prime_sieve(5500000):
        if p % 4 == 1:
            q_primes.append(p)
        else:
            p_primes.append(p)

    def count(x, start = 0):
        total = x
        for i in range(start, len(p_primes)):
            if p_primes[i] * x > N:
                break

            total += count(p_primes[i] * x, i)
        return total

    def candidates():
        for a in q_primes:
            if a ** 3 > N: 
                break
            for b in q_primes:
                if b == a: 
                    continue
                if a ** 3 * b ** 2 > N: 
                    break
                for c in q_primes:
                    if c == a or c == b:
                        continue
                    if a ** 3 * b ** 2 * c > N: 
                        break
                    yield a ** 3 * b ** 2 * c

        for a in q_primes:
            if a ** 10 > N:
                break
            for b in q_primes:
                if b == a: 
                    continue
                if a ** 10 * b ** 2 > N:
                    break
                yield a ** 10 * b ** 2

        for a in q_primes:
            if a ** 7 > N: 
                break
            for b in q_primes:
                if b == a: 
                    continue
                if a ** 7 * b ** 3 > N: 
                    break
                yield a ** 7 * b ** 3    


    return sum(count(c) for c in candidates())

print(solution())