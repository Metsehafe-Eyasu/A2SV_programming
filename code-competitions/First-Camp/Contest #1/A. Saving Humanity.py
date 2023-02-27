from collections import defaultdict
cases = int(input())
for _ in range(cases):
    total, iterations = list(map(int, input().split()))
    soldiers = list(map(int, [*input()]))
    forward = 0
    window = []
    for i in range(total):
        backward = 0
        if soldiers[i] == 1:
            forward = backward = iterations
        while window and soldiers[i] == 1 and backward > 0:
            index = window.pop()
            soldiers[index] = 1
            backward -= 1
        
        if forward > 0 and soldiers[i] == 0:
            soldiers[i] = 1
            forward -= 1
        print(soldiers)
        window.append(i)
    print(soldiers)  
            
    
    