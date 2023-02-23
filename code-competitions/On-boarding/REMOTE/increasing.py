cases = int(input())
for _ in range(cases):
    array = list(map(int, input().split()))
    arraySet = set(array)
    if len(array)!= len(arraySet):
        print('YES')
    else:
        print('NO')