from bisect import bisect_right, bisect_left 
cases = int(input())
for _ in range(cases):
    length, left, right = list(map(int, input().split()))
    array = sorted(list(map(int, input().split())))
    pairs = 0
    
    for i in range(length):
        pairs += bisect_right(array, right - array[i])
        pairs -= bisect_left(array, left - array[i])
        
        if left <= array[i]*2 and array[i]*2 <= right:
            pairs -= 1
            
    print(pairs//2)