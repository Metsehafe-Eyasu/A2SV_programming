cases = int(input())
for _ in range(cases):
    string = list(map(int, [*input()]))
    length = len(string)
    
    one = 0
    two = 0
    three = 0
    
    right = 0
    left = 0
    minimumLen = float('inf')
    
    while right < length:
        if string[right] == 1:
            one +=1
        elif string[right] == 2:
            two += 1
        elif string[right] == 3:
            three += 1
        
        while left < right and one > 0 and two > 0 and three > 0:
            minimumLen = min(minimumLen, (one + two + three))
            if string[left] == 1:
                one -=1
            elif string[left] == 2:
                two -= 1
            elif string[left] == 3:
                three -= 1
            left += 1
                  
        right += 1
        
    if minimumLen == float('inf'):
        print(0)
    else:
        print(minimumLen)
    