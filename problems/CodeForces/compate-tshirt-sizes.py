compares = int(input())
for index in range(compares):
    right, left = input().split()
    rightLen = len(right)
    leftLen = len(left)
    if right == left:
        print('=')
    elif right[-1] == 'L'  and (left[-1] == 'S' or left[-1] == 'M'):
        print('>')
    elif right[-1] == 'S'  and (left[-1] == 'L' or left[-1] == 'M'):
        print('<')
    elif right[-1] == 'M'  and left[-1] == 'S':
        print('>')
    elif right[-1] == 'M'  and left[-1] == 'L':
        print('<')
    elif right[-1] == 'S'  and left[-1] == 'S':
        if rightLen > leftLen:
            print('<')
        else:
            print('>')
    elif right[-1] == 'L'  and left[-1] == 'L':
        if rightLen > leftLen:
            print('>')
        else:
            print('<')