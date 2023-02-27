class Solution:
    def maxSumRangeQuery(self, nums: List[int], requests: List[List[int]]) -> int:
        length = len(nums)
        prefix = [0]*(length+2)
        for left, right in requests:
            prefix[left+1] += 1
            prefix[right+2] -= 1
        for i in range(1, length+1):
            prefix[i] += prefix[i-1]
        prefix = prefix[1:length+1]
        prefix.sort()
        answer = 0
        nums.sort()
        for i in range(length):
            answer += nums[i]*prefix[i]
        return answer%(10**9 + 7)