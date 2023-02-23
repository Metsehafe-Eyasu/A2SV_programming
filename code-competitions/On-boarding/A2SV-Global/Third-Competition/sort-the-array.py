size = int(input())
array = list(map(int, input().split()))

start = 0
end = size-1

while start < size-1:
    if array[start] > array[start+1]:
        break
    start += 1

while end > start:
    if array[end] < array[end - 1]:
        break
    end -= 1


if (end != size-1 and array[start] > array[end+1]) or (start != 0 and array[end] < array[start-1]):
    print('no')
    exit()
    
for i in range(end, start, -1):
    if array[i] > array[i-1]:
        print('no')
        exit()

print('yes')
print(start+1, end+1)