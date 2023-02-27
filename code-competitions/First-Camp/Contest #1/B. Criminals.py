cases = int(input())
for _ in range(cases):
    length = int(input())
    criminals = list(map(int, input().split()))
    stack = list()
    
    ops = 0
    for i in range(length):
        while stack and criminals[i] == 0:
            top = stack.pop()
            criminals[i] += 1
            if criminals[top] > 2:
                stack.append(top)
            criminals[top] -= 1
            ops += 1
        if criminals[i] != 0:
            stack.append(i)
    for i in range(length - 1):
        ops += criminals[i]
    print(ops)
                