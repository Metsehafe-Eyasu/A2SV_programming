cases = int(input())
for _ in range(cases):
    length = int(input())
    array = list(map(int, input().split()))
    array.sort()
    
    checker = False
    for i in range(length-1):
        if array[i+1] - array[i] > 1:
            checker = True
            break
    if checker:
        print('NO')
    else:
        print('YES')