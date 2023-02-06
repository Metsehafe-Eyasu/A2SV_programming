row, col = list(map(int, input().split()))
matrix = [[*input()] for _ in range(row)]

# print(*matrix, sep="\n")

answer = []

for i in range(row):
    for j in range(col):
        noDuplicates = True
        for k in range(row):
            if k != i and matrix[i][j] == matrix[k][j]:
                noDuplicates = False
                break
        if not noDuplicates:
            continue
        for k in range(col):
            if k != j and matrix[i][j] == matrix[i][k]:
                noDuplicates = False
                break
        if noDuplicates:
            answer.append(matrix[i][j])
print(*answer, sep="")
        