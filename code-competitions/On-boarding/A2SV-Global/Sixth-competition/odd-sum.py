size = int(input())
array = list(map(int, input().split()))

firstHalf = array[:size]
secondHalf = array[size:] 

firstSet = set(firstHalf)
secondSet = set(secondHalf)

swappedF = 0
swappedS = 0
for i in firstSet:
    for j in secondSet:
        if i != j:
            swappedF = i
            swappedS = j
            break
if swappedF == 0:
    print(-1)
else:
    if sum(firstHalf) != sum(secondHalf):
        print(*array)
    else:
        firstHalf.remove(swappedF)
        firstHalf.append(swappedS)
        secondHalf.remove(swappedS)
        secondHalf.append(swappedF)

        print(*firstHalf, *secondHalf)