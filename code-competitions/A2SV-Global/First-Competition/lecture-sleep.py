from collections import deque

lecture, technique = list(map(int, input().split()))
lectureHours = list(map(int, input().split()))
miksha = list(map(int, input().split()))

total = 0
for i in range(lecture):
    if miksha[i] == 1:
        total+= lectureHours[i]

window = deque([])
for i in range(technique):
    if miksha[i] == 1:
        window.append(0)
    else:
        window.append(lectureHours[i])
maxSum = total
sum = total
for i in window:
    sum+= i

if sum > maxSum:
    maxSum = sum

for i in range(technique, lecture):
    left = window.popleft()
    if miksha[i] == 1:
        window.append(0)
    else:
        window.append(lectureHours[i])
    sum = total
    for i in window:
        sum+= i
    if sum > maxSum:
        maxSum = sum
        
print(maxSum)