length = int(input())
array = list(map(int, input().split()))

coins = 0
count = 0
zeroCount = False
     
for i in array:
    if i < 0:
        coins += abs(i+1)
        count += 1
    elif i == 0:
        coins += 1
        zeroCount += 1
    else:
        coins += i-1

if count%2 == 1 and not zeroCount:
    coins += 2

print(coins)