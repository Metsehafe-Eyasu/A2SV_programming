cases = int(input())
for _ in range(cases):
    length = int(input())
    array = list(map(int, input().split()))
    
    stack = list()
    left = 0
    right = length-1
    while left<=right:
        stack.append(array[left])
        if right == left:
            break
        stack.append(array[right])
        left += 1
        right -= 1
    print(*stack)