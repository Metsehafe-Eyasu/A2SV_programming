cases = int(input())
for _ in range(cases):
    rows, columns = list(map(int, input().split()))
    matrix = [[*input()] for _ in range(rows)]
    for i in range(columns):
        last = rows-1
        
        for j in range(rows-1, -1, -1):
            if matrix[j][i] == '*':
                matrix[last][i], matrix[j][i] = matrix[j][i], matrix[last][i]
                last -= 1
            elif matrix[j][i] == 'o':
                last = j-1
    answer = [''.join(matrix[i]) for i in range(rows)]
    
    print(*answer, sep='\n')
        
                
            