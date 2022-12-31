tourists = int(input())
points = list(map(int, input().split()))
amazing = 0
max = -float('inf')
min = float('inf')

for i in range(1, tourists):
    if points[i] > points[0] and points[i] > max:
        amazing += 1
        max = points[i]
    elif points[i] < points[0] and points[i] < min:
        amazing += 1
        min = points[i]
print(amazing)