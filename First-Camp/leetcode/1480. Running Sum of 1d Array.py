class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        total = 0
        answer = []
        for num in nums:
            total += num
            answer.append(total)
        return answer