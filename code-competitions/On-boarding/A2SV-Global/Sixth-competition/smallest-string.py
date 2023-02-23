cases = int(input())
for _ in range(cases):
    lenA, lenB, maxOps = list(map(int, input().split()))

    stringA = [*input()]
    stringB = [*input()]
    
    stringA.sort()
    stringB.sort()
    
    indA = 0
    indB = 0
    
    countA = 0
    countB = 0
    
    answer = []
    endFirst = False
    
    while indA < lenA and indB < lenB:
        if (stringA[indA] < stringB[indB] and countA < maxOps) or countB >= maxOps:
            countB = 0
            countA += 1
            
            answer.append(stringA[indA])
            indA += 1
        else:
            countA = 0
            countB += 1
            answer.append(stringB[indB])
            indB += 1
        
    print(*answer, sep='')