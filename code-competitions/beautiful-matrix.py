for i in range(5):
    row = list(map(int, input().split()))
    for j in range(5):
        if row[j] == 1:
            switchX = abs(i - 2)
            switchY = abs(j - 2)
            print(switchY + switchX)
