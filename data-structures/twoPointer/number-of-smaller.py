n, m = list(map(int, input().split()))
firstArray = list(map(int, input().split()))
secondArray = list(map(int, input().split()))
    
count = 0
currentPtr = 0
answer = []
for i in range(m):
    if currentPtr == n:
        answer.append(count)
    else:
        while currentPtr < n:
            if firstArray[currentPtr] >= secondArray[i]:
                break
            count += 1
            currentPtr += 1
        answer.append(count)
print(*answer)