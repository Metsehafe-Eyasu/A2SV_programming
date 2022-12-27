class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        placer = 0
        length = len(nums)
        for i in range(length):
            print(nums)
            if nums[i] != val:
                nums[placer] = nums[i]
                placer += 1
        return placer