length = int(input())
students = sorted(list(map(int, input().split())))

count = 1
maxSize = 1
index = 0
for i in range(1, length):
    count += 1
    if students[i] - students[index] > 5:
        while(students[i] - students[index] > 5 ):
            count -= 1
            index += 1
    maxSize = max(count, maxSize)

print(maxSize)
