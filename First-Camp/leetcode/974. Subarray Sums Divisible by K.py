class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        prefSum = defaultdict(int)
        answer = currSum = 0
        prefSum[0] = 1
        for i in nums:
            currSum = (currSum + i) % k
            if currSum < 0:
                currSum += k
            answer += prefSum[currSum]
            prefSum[currSum] += 1
        return answer