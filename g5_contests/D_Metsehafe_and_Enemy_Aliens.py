def intInput(): return int(input())
def intList(): return list(map(int, input().split()))
def strInput(): return input()


def solution():
    n = intInput()
    nums = intList()
    nums.sort()
    left = combo = result = 0
    right = n - 1
    while left < right:
        combo += nums[left]
        if combo >= nums[right]:
            result += nums[right] + 1
            combo -= nums[right]
            right -= 1
        left += 1
    if left == right:
        combo += nums[left]
    result += ((combo + 1)//2 + 1) if combo > 1 else combo 
    return result




cases = intInput()
# cases = 1
for i in range(cases):
    print(solution())