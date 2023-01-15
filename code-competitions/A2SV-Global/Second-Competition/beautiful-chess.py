from collections import defaultdict
cases = int(input())

for _ in range(cases):
    chessboard = []
    space = input()
    for _ in range(8):
        row = list(input())
        chessboard.append(row)
    # print(*chessboard, sep='\n')
    
    edges = []
    for i in range(8):
        if chessboard[0][i] == '#' and [0, i] not in edges:
            edges.append([0, i])
        if chessboard[7][i] == '#' and [7, i] not in edges:
            edges.append([7, i])
        if chessboard[i][0] == '#' and [i, 0] not in edges:
            edges.append([i, 0])
        if chessboard[i][7] == '#' and [i, 7] not in edges:
            edges.append([i, 7])
    # print(edges)

    diagonal = []
    for i in range(3):
        found = False
        for j in range(i+1, 4):
            # print(j)
            if sum(edges[i]) == sum(edges[j]):
                diagonal.append(sum(edges[i]))
                found = True
                break
        if found:
            break
    for i in range(4):
        found = False
        for j in range(i+1, 4):
            if edges[i][0] - edges[i][1] == edges[j][0] - edges[j][1]:
                diagonal.append(edges[i][0] - edges[i][1])
                found = True
                break
        if found:
            break
    # print(diagonal)
    row = int(sum(diagonal)/2)
    col = int(abs(row - max(diagonal)))
    print(row+1, col+1)
