class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        placer = 0
        length = len(nums)
        for i in range(length):
            if nums[i] != nums[placer]:
                placer += 1
                nums[placer] = nums[i]
        return placer+1