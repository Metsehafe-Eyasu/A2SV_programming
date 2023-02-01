class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        length = len(nums)
        rotations = length - (k % length)
        answer = nums[rotations:] + nums[:rotations]
        for i in range(length):
            nums[i] = answer[i]