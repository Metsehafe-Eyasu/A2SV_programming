cases = int(input())
for _ in range(cases):
    n, k = list(map(int, input().split()))
    numbers = list(map(int, input().split()))
    checkSet = set()
    checker = False
    for i in numbers:
        if k + i in checkSet or i - k in checkSet:
            checker = True
            print('YES')
            break
        checkSet.add(i)
    if not checker:
        print('NO')
        