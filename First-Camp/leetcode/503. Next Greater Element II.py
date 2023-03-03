class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        length = len(nums)
        stack = []
        dictMap = defaultdict(lambda: -1)

        for i in range(2*length):
            while stack and nums[stack[-1]] < nums[i%length]:
                dictMap[stack.pop()] = nums[i%length]
            stack.append(i%length)
        return [dictMap[i] for i in range(length)]
