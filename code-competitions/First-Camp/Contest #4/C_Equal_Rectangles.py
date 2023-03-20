def intInput(): return int(input())
def intList(): return list(map(int, input().split()))
def strInput(): return input()


def solution():
    count = intInput()
    sides = sorted(intList())
    
    left = 0
    right = len(sides) - 1
    
    area = sides[left]*sides[right]
    
    while left < right:
        if sides[left] == sides[left+1] and sides[right] == sides[right-1] and sides[left]*sides[right] == area:
            left += 2
            right -= 2
        else:
            return 'NO'
    
    return 'YES'

cases = intInput()
# cases = 1
for i in range(cases):
    print(solution())