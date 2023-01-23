from collections import deque
cases = int(input())
for _ in range(cases):
    total = int(input())
    planks = list(map(int, input().split()))
    bases = deque()
    currMax = 0
    if total == 2:
        print(0)
    else:
        for i in planks:
            if i >= currMax:
                bases.append(i)
                currMax = i
            
            if len(bases) > 2:
                bases.popleft()
        smallerBase = min(bases)
        answer = min(smallerBase - 1, total-2)
        print(answer)