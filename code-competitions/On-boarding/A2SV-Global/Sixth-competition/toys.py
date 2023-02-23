from collections import defaultdict
tagsCount, wanted = list(map(int, input().split()))
tags = list(map(int, input().split()))
tags.sort()
wantedDict = defaultdict(int)
for _ in range(wanted):
    wantedDict[input()] += 1

reverseSortedWants = dict(sorted(wantedDict.items(), key=lambda item: item[1], reverse=True))

bestPrice = 0
worstPrice = 0

indexBest = 0
indexWorst = tagsCount-1
for i in reverseSortedWants:
    bestPrice += reverseSortedWants[i]*tags[indexBest]
    worstPrice += reverseSortedWants[i]*tags[indexWorst]
    indexBest += 1
    indexWorst -= 1

print(bestPrice, worstPrice)
