length = int(input())
names = input().split()
cases = int(input())
for _ in range(cases):
    name = input()
    left = 0
    right = length-1
    while left <= right:
        mid = left + (right - left) // 2
        if names[mid] >= name:
            right = mid - 1
        else:
            left = mid + 1
    print(left)