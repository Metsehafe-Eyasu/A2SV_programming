cases = int(input())
for _ in range(cases):
    length, k = list(map(int, input().split()))
    array = list(map(int, input().split()))
    
    count = 0
    temp = 1
    
    for i in range(length-1):
        if array[i] < 2*array[i+1]:
            temp += 1
        else:
            temp = 1
        if temp == k+1:
            count+=1
            temp=k
    print(count)