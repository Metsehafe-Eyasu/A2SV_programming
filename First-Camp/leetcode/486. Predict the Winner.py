class Solution:
    def optimize(self, nums: List[int], left: int, right: int) -> int:
        if left == right:
            return nums[left]
        
        rightChosen = nums[right] - self.optimize(nums, left, right-1)
        leftChosen = nums[left] - self.optimize(nums, left+1, right)

        return max(rightChosen, leftChosen)

    def PredictTheWinner(self, nums: List[int]) -> bool:
        length = len(nums)
        answer = self.optimize(nums, 0, length-1)
        return answer >= 0
