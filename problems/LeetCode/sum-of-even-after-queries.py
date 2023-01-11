class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        currSum = 0
        for i in nums:
            if i%2 == 0:
                currSum += i

        stack = []
        for value, index in queries:
            if nums[index]%2 == 0:
                currSum -= nums[index]

            nums[index] += value

            if nums[index]%2 == 0:
                currSum += nums[index]
                
            stack.append(currSum)
            
        return stack