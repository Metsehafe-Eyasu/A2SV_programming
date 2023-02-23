cases = int(input())
for _ in range(cases):
    a1, b1 = list(map(int, input().split()))
    a2, b2 = list(map(int, input().split()))
    if (a1 == a2 and b1 + b2 == a1):
        print('YES')
    elif (a1 == b2 and b1 + a2 == a1):
        print('YES')
    elif (b1 == a2 and a1 + b2 == b1):
        print('YES')
    elif (b1 == b2 and a1 +a2 == b1):
        print('YES')
    else:
        print('NO')
    