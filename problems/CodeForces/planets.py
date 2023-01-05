from collections import defaultdict
testCases = int(input())
for i in range(testCases):
    totalPlanets, cost = list(map(int, input().split()))
    planetsList = list(map(int, input().split()))
    orbits = defaultdict(int)
    for i in planetsList:
        orbits[i] += 1
    sum = 0
    for index in orbits:
        if orbits[index] >= cost:
            sum += cost
        else:
            sum += orbits[index]
    print(sum)