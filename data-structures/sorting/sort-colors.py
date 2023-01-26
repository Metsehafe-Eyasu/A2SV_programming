class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        start = 0
        end = len(nums) - 1
        current = 0
        while current <= end:
            if nums[current] == 0:
                nums[current], nums[start] = nums[start], nums[current]
                current+=1
                start+=1
            elif nums[current] == 2:
                nums[current], nums[end] = nums[end], nums[current]
                end-=1
            else:
                current+=1
