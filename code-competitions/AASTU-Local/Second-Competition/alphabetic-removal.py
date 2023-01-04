from collections import defaultdict, deque

length, removal = list(map(int, input().split()))
string = [*input()]

alphabet = 'abcdefghijklmnopqrstuvwxyz'

indexedDic = defaultdict(deque)

for index, val in enumerate(string):
    indexedDic[val].append(index)

deleted = set()


for i in range(removal):
    dicLength = len(indexedDic)
    alIndex = 0
    for i in range(26):
        letter = alphabet[alIndex]
        if len(indexedDic[letter]) > 0:
            deleted.add(indexedDic[letter].popleft())
            break
        alIndex += 1

answer = ''
for i in range(length):
    if i not in deleted:
        answer += string[i]
print(answer, end='')
