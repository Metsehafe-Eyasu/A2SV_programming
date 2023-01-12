class Solution:
    def applyOperations(self, nums: List[int]) -> List[int]:
        length = len(nums)
        for i in range(length - 1):
            if nums[i] == nums[i+1]:
                nums[i] *= 2
                nums[i+1] = 0
        placer = 0
        for i in range(length):
            if nums[i] != 0:
                temp = nums[i]
                nums[i] = nums[placer]
                nums[placer] = temp
                placer += 1
        return nums