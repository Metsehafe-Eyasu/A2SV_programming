class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        length = len(nums)
        answer = 0
        currSum = 0
        prefSum = defaultdict(int)
        for i in range(length):
            currSum += nums[i]
            if currSum == k:
                answer += 1
            if currSum - k in prefSum:
                answer += prefSum[currSum-k]
            prefSum[currSum] += 1
        return answer