from itertools import accumulate
students, minSum, maxSum = list(map(int, input().split()))

studList = list(map(int, input().split()))
prefix = list(accumulate(studList, initial=0))
left = 0
groups = 0
for right in range(students+1):
    if prefix[right] - prefix[left] <= maxSum and prefix[right] - prefix[left] >= minSum:
            groups += 1
            
    while left < right and prefix[right] - prefix[left] >= minSum:
        left += 1
        if prefix[right] - prefix[left] <= maxSum and prefix[right] - prefix[left] >= minSum:
            groups += 1
    
print(groups)   
