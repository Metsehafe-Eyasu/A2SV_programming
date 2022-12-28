# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import defaultdict
firstGroup, secondGroup = map(int, input().split())

listDict = defaultdict(list)

for i in range(firstGroup):
    listDict[input()].append(i+1)

for i in range(secondGroup):
    index = listDict[input()]
    if index:
        print(*index) 
    else:
        print(-1)
