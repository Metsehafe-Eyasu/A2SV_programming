length = int(input())
array = list(map(int, input().split()))

swapIndices = []

for i in range(length-1):
    minIndex = i
    for j in range(i+1, length):
        if array[j] < array[minIndex]:
            minIndex = j
    if minIndex != i:
        array[minIndex], array[i] = array[i], array[minIndex]
        swapIndices.append([minIndex, i])

print(len(swapIndices))
for i in swapIndices:
    print(*i)