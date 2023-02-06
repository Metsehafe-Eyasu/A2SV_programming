row, col = list(map(int, input().split()))
matrix = [[*input()] for _ in range(row)]

print(*matrix, sep="\n")

for i in range(row):
    for j in range(col):
        