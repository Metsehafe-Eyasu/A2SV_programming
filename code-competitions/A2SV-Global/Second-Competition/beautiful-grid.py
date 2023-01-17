cases = int(input())
for _ in range(cases):
    side = int(input())
    matrix = []
    for _ in range(side):
        row = list(map(int, list(input())))
        matrix.append(row)
    turn = 0
    portion = side//2
    portion2 = portion+1 if side%2 != 0 else portion
    for i in range(portion2):
        for j in range(portion):
            transposes = [matrix[i][j], 
                        matrix[side-1-j][i], 
                        matrix[side-1-i][side-1-j], 
                        matrix[j][side-1-i]]
            zero = transposes.count(0)
            one = transposes.count(1)
            turn += min(zero, one)
    print(turn)
    

