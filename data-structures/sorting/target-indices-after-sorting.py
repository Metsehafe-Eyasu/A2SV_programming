class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        nums.sort()
        length = len(nums)
        answer = []
        for i in range(length):
            if nums[i] == target:
                answer.append(i)
        return answer
