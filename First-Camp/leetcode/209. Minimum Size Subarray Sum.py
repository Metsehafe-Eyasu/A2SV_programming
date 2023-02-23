class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        length = len(nums)
        maxSize = float('inf')
        size = 0
        total = 0
        r = 0
        for i in range(length):
            total += nums[i]
            size += 1
            while r <= i and total >= target:
                maxSize = min(maxSize, size)
                total -= nums[r]
                size -= 1
                r += 1

        return maxSize if maxSize != float('inf') else 0
