count = [[0] * 10 for _ in range(10)]

for i in range(10):
    for j in range(10 - i):
        count[i][j] = 9 - i - j

for k in range(17):
    temp = [[0] * 10 for _ in range(10)]

    for x in range(10):
        for y in range(10 - x):
            for j in range(10 - x - y):
                temp[y][j] += count[x][y]

    count = temp

print(sum(map(sum, count)))