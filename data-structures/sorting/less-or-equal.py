n, k = list(map(int, input().split()))
array = list(map(int, input().split()))

array.sort()

if n == k:
    print(array[k-1])
elif k == 0:
    if array[0] <= 1:
        print(-1)
    else:
        print(1)
elif array[k-1] != array[k]:
    print(array[k-1])
elif array[k-1] == array[k]:
    print(-1)
