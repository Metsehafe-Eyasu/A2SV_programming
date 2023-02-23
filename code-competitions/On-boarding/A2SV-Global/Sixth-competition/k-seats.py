rows, cols, seats = list(map(int, input().split()))
matrix = [[*input()] for _ in range(rows)]

arrangements = 0

for i in range(rows):
    available = 0
    for j in range(cols):
        available = 0 if matrix[i][j] != '.' else available + 1
        if available >= seats:
            arrangements += 1

for i in range(cols):
    available = 0
    for j in range(rows):
        available = 0 if matrix[j][i] != '.' else available + 1
        if available >= seats:
            arrangements += 1
if seats == 1:
    arrangements //= 2

print(arrangements)