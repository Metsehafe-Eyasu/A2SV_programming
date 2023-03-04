students, minSum, maxSum = list(map(int, input().split()))
studList = list(map(int, input().split()))

def atMost(nums, k) -> int:
    length = len(nums)
    if k < 0: return 0
    left = ans = 0
    for right in range(length):
        k -= nums[right]
        while k < 0:
            k += nums[left]
            left += 1
        ans += right - left + 1
    return ans

print(atMost(studList, maxSum) - atMost(studList, minSum - 1)) 