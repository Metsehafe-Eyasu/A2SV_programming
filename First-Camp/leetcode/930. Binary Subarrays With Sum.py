class Solution:
    def atMost(self, nums: List[int], k: int) -> int:
        if k < 0:
            return 0
        length = len(nums)
        ans = left = 0
        for right in range(length):
            k -= nums[right]
            while k < 0:
                k += nums[left]
                left += 1
            ans += right - left + 1
        return ans
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        return self.atMost(nums, goal) - self.atMost(nums, goal - 1)
