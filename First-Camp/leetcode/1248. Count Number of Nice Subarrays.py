class Solution:
    def numberOfSubarrays(self, nums: list[int], k: int) -> int:
        return self.atMost(nums, k) - self.atMost(nums, k-1)
        
    def atMost(self, nums: list[int], k: int) -> int:
        length = len(nums)
        ans = left = 0
        for right in range(length) :
            if nums[right]%2 == 1:
                k -= 1
            while k < 0:
                k += nums[left]%2
                left += 1
            ans += right - left + 1
        return ans 