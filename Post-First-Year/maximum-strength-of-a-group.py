class Solution:
    def maxStrength(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        pos = []
        neg = []
        zero = False
        for num in nums:
            if num > 0:
                pos.append(num)
            elif num < 0:
                neg.append(num)
            else:
                zero = True
        pos.sort()
        neg.sort()
        prod = 1 if pos or len(neg) > 1 or not zero else 0 
        i = 0
        while i + 1 < len(neg):
            prod *= neg[i]*neg[i+1]
            i+=2
        for i in pos:
            prod *= i
        return prod