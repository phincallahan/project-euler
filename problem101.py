import numpy as np

def get_polynomial(coef):
    def f(x):
        return sum([ c * x ** n for n, c in enumerate(coef)])

    return f

def main():
    # coef = [1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1]
    coef = [0, 0, 0, 1]
    N = len(coef)

    f = get_polynomial(coef)
    y = np.array(map(f, range(1, N + 1)))
    A = np.empty((N, N))

    for i in range(N):
        for j in range(N):
            A[i, j] = (i + 1) ** j
        
    print(y)
    print(A)

    s = 0
    for i in range(11):
        B = np.linalg.inv(A[0:(i + 1), 0:(i + 1)])
        op = get_polynomial(np.dot(B, y[0:(i+1)]))
        i = 1
        while abs(f(i) - op(i)) < .00001:
            i += 1

        s += op(i)

    # print(s)

if __name__ == "__main__":
    main()