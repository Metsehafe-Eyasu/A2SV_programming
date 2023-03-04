class Solution:
    def findFirst(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        while left <= right:
            middle = (right + left) // 2
            if nums[middle] >= target:
                right = middle - 1
            else:
                left = middle + 1
        return left
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        low = self.findFirst(nums, target)
        high = self.findFirst(nums, target + 1) - 1
        if low < len(nums) and nums[low] == target:
            return [low, high]
        return [-1, -1]