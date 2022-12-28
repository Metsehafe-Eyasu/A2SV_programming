class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        length = len(nums)
        count = 0
        for i in range(length - 1):
            for j in range(i+1, length):
                if nums[i] == nums[j]:
                    count+=1
        return count