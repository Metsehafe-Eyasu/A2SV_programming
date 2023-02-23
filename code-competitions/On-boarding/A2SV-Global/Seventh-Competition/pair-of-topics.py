length = int(input())
teacher = list(map(int, input().split()))
student = list(map(int, input().split()))
count = 0
for i in range(length - 1):
    for j in range(i+1, length):
        if student[i] + student[j] < teacher[i] + teacher[j]:
            count += 1
print(count) 