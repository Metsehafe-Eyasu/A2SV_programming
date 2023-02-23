class NumArray:

    def __init__(self, nums: List[int]):
        self.prefix_sum = [0]*(len(nums)+1)
        total = 0
        for ind, val in enumerate(nums):     
            total += val
            self.prefix_sum[ind+1] = total
    def sumRange(self, left: int, right: int) -> int:
        return self.prefix_sum[right+1] - self.prefix_sum[left]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)