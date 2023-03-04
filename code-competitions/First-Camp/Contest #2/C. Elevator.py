cases = int(input())
for _ in range(cases):
    walkTime, elevTime, currentFloor = list(map(int, input().split()))
    if walkTime <= elevTime:
        print(walkTime*4)
        continue
    
    minTime = float('inf')
    for i in range(0, currentFloor+1):
        foot = i*walkTime
        elev = (currentFloor + 4 - i - i) * elevTime
        minTime = min(minTime, foot + elev)
    print(minTime)