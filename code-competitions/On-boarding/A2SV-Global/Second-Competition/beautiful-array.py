size = int(input())
array = list(map(int, input().split()))

array.sort()
negativeSet = set()
positiveSet = set()
zeroSet = set()

negativeSet.add(array[0])
i = 1
while i < size:
    if array[i] == 0:
        zeroSet.add(array[i])
    elif array[i] < 0 and array[i + 1] < 0:
        positiveSet.add(array[i])
        positiveSet.add(array[i+1])
        i += 1
    elif array[i] < 0:
        zeroSet.add(array[i])
    else:
        positiveSet.add(array[i])
    i += 1

print(len(negativeSet), *negativeSet)
print(len(positiveSet), *positiveSet)
print(len(zeroSet), *zeroSet)