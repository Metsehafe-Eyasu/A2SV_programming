position = input()
totalMoves = 8

if (position[0] == 'a' or position[0] == 'h') and (position[1] == '1' or position[1] == '8'):
    totalMoves -= 5
elif (position[0] == 'a' or position[0] == 'h') or (position[1] == '1' or position[1] == '8'):
    totalMoves -= 3

print(totalMoves)