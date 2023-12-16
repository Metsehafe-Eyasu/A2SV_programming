class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        placer = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i-1]:
                nums[placer] = nums[i]
                placer += 1
        return placer
        