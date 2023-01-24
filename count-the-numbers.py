n, m = list(map(int, input().split()))
firstArray = list(map(int, input().split()))
secondArray = list(map(int, input().split()))

currentPtr = 0
answer = []
for i in range(m):
    if currentPtr == n:
        answer.append(currentPtr)
    else:
        while currentPtr < n:
            if firstArray[currentPtr] >= secondArray[i]:
                break
            currentPtr += 1
        answer.append(currentPtr)
print(answer)