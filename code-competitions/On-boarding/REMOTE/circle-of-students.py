queries = int(input())
for _ in range(queries):
    length = int(input())
    circle = list(map(int, input().split()))
    diff = abs(circle[0] - circle[length-1])
    checker = True
    for i in range(length):
        diff = abs(circle[i] - circle[(i+1)%length])
        if diff != 1 and diff != length - 1:
            checker = False
            break
    if not checker:
        print('NO')
    else:
        print('YES')