length = int(input())
array = list(map(int, input().split()))

array.sort()

if array[length-3] + array[length-2] <= array[length-1]:
    print('NO')
else:
    print('YES')
    array[length-1], array[length-2] = array[length-2], array[length-1]
    print(*array)