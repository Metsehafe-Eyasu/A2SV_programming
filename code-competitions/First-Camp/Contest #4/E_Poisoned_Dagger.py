def intInput(): return int(input())
def intList(): return list(map(int, input().split()))
def strInput(): return input()

def binary_search(array, damage) -> int:
    
    def condition(currentRange) -> bool:
        currDam = 0
        length = len(array)
        for i in range(1, length):
            if array[i] - array[i-1] < currentRange:
                currDam += array[i] - array[i-1]
            else:
                currDam += currentRange
        currDam += currentRange
        if currDam >= damage:
            return True
        return False # end of condition

    left, right = 1, damage
    while left < right:
        mid = left + (right - left) // 2
        if condition(mid):
            right = mid
        else:
            left = mid + 1
    return left


def solution():
    attacks, damageNeeded = intList()
    attackTimes = sorted(intList())
    return binary_search(attackTimes, damageNeeded)

cases = intInput()
# cases = 1
for i in range(cases):
    print(solution())