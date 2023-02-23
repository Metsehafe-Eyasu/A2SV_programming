boysCount = int(input())
boys = list(map(int, input().split()))
boys.sort()

girlsCount = int(input())
girls = list(map(int, input().split()))
girls.sort()

setG = set()

count = 0

for i in range(boysCount):
    for j in range(girlsCount):
        if j not in setG and abs(girls[j] - boys[i]) <= 1:
            count += 1
            setG.add(j)
            break

print(count)