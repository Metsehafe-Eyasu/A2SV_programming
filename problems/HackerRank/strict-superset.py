# Enter your code here. Read input from STDIN. Print output to STDOUT
superSet = set(map(int, input().split()))
otherSets = int(input())
setsList = []
for i in range(otherSets):
    s = set(map(int, input().split()))
    setsList.append(s)

isStrict = True
for currentSet in setsList:
    l = len(currentSet.difference(superSet))
    if l > 0:
        isStrict = False
        break
    
print(isStrict)