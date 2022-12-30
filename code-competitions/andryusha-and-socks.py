totalPairs = int(input())
order = list(map(int, input().split()))
table = set()
maxSocks = 0
for i in order:
    if i in table:
        table.remove(i)
    else:
        table.add(i)
        length = len(table)
        maxSocks = max(length, maxSocks)
print(maxSocks) 