length = int(input())
array = list(map(int, input().split()))

even = False
odd = False

for i in array:
    if i % 2 == 0:
        even = True
    else:
        odd = True

    if even and odd:
        break
if even and odd:
    print(*sorted(array))
else:
    print(*array)
