cases = int(input())
for _ in range(cases):
    matrix = [list(map(int, input().split())) for _ in range(2)]
    minIndex = ()
    minVal = float('inf')
    maxIndex = ()
    maxVal = -float('inf')
    
    # Find min and max values
    for i in range(2):
        for j in range(2):
            if matrix[i][j] < minVal:
                minVal = matrix[i][j]
                minIndex = (i, j)
            
            if matrix[i][j] > maxVal:
                maxVal = matrix[i][j]
                maxIndex = (i, j)
    
    if minIndex[0] == 1 - maxIndex[0] and minIndex[1] == 1 - maxIndex[1]:
        print('YES')
    else:
        print('NO')