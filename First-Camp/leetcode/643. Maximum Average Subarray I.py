class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        length = len(nums)
        window = sum(nums[:k])
        maxSum = window
        for i in range(k, length):
            window = window + nums[i] - nums[i-k]
            if window > maxSum:
                maxSum = window
        return maxSum/k