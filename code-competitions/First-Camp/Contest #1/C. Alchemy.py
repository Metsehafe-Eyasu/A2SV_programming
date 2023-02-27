length = int(input())
ingredients = list(map(int, input().split()))
right = length - 1
left = 0

ed = 0
alph = 0

while left <= right:
    if ed <= alph:
        ed += ingredients[left]
        left += 1
        
    else:
        alph += ingredients[right]
        right -= 1
print(right + 1, length - left)
    