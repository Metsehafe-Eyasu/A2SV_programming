class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        placer = 0
        for i in range(length):
            if nums[i] != 0:
                temp = nums[i]
                nums[i] = nums[placer]
                nums[placer] = temp
                placer += 1