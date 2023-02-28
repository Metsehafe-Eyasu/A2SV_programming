class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        stack = []
        maxVal = -float('inf')
        for val in reversed(nums):
            if val < maxVal: return True
            while stack and stack[-1] < val:
                maxVal = stack.pop()
            stack.append(val)
        return False