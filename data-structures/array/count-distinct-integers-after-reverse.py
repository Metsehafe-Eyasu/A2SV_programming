class Solution:
    def countDistinctIntegers(self, nums: List[int]) -> int:
        length = len(nums)
        for i in range(length):
            rev = str(nums[i])[::-1]
            nums.append(int(rev))
        newNum = len(set(nums))
        return newNum