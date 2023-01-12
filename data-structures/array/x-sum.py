from collections import defaultdict
testCases = int(input())

for _ in range(testCases):
    rightDiagonal = defaultdict(int)
    leftDiagonal = defaultdict(int)
    chessboard = []
    rows, columns = list(map(int, input().split()))
    for index in range(rows):
        row = list(map(int, input().split()))
        chessboard.append(row)
        length = len(row)
        for i in range(length):
            rightDiagonal[index - i] += row[i]
            leftDiagonal[index + i] += row[i]
    maxSum = -1
    for i in range(rows):
        for j in range(columns):
            sum = rightDiagonal[i-j] + leftDiagonal[i+j] - chessboard[i][j]
            maxSum = max(maxSum, sum)
    print(maxSum)