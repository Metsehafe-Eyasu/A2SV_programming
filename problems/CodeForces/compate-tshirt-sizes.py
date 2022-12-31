compares = int(input())
sizes = {'S': 0, 'M':1, 'L':2}
for i in range(compares):
    shirts = input().split()
    if sizes[shirts[0][-1]] < sizes[shirts[1][-1]]:
        print('<')
    elif sizes[shirts[0][-1]] > sizes[shirts[1][-1]]:
        print('>')
    else:
        right = len(shirts[0])
        left = len(shirts[1])
        if right > left:
            if shirts[0][-1] == 'S':
                print('<')
            else:
                print('>')
        elif left < right:
            if shirts[0][-1] == 'S':
                print('>')
            else:
                print('<')
        else:
            print('=')