length = int(input())
days = list(map(int, input().split()))

count = 1
maxSequence = 0

for i in range(length-1):
    if days[i] > days[i+1]:
        count = 1
        continue
    count += 1
    maxSequence = max(count, maxSequence)

print(maxSequence)