class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        ans = []
        length = len(nums)
        for i in range(length):
            ans.append(nums[nums[i]])
        return ans
