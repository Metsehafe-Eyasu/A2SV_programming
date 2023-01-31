lenFirst, lenSecond = list(map(int, input().split()))
firstArr = list(map(int, input().split()))
secondArr = list(map(int, input().split()))

firstPtr = 0
secondPtr = 0
answer = []
while firstPtr < lenFirst and secondPtr < lenSecond:
    if firstArr[firstPtr] < secondArr[secondPtr]:
        answer.append(firstArr[firstPtr])
        firstPtr += 1
    else:
        answer.append(secondArr[secondPtr])
        secondPtr += 1

if firstPtr == lenFirst and secondPtr < lenSecond:
    answer.extend(secondArr[secondPtr:])
if secondPtr == lenSecond and firstPtr < lenFirst:
    answer.extend(firstArr[firstPtr:])

print(*answer)
