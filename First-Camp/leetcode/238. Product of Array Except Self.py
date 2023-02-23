class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix_sum = []
        product = 1
        length = len(nums)
        for i in nums:
            prefix_sum.append(product)
            product *= i
        
        product = 1
        for i in range(length-1, -1, -1):
            prefix_sum[i] *= product
            product *= nums[i]
        
        return prefix_sum