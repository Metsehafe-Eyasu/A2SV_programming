from collections import defaultdict
class Solution:
    def maxOperations(self, nums: list[int], k: int) -> int:
        checkList = defaultdict(int)
        numberOfOperations = 0
        for i in nums:
            if checkList[k-i] > 0:
                numberOfOperations += 1
                checkList[k-i] -= 1
            else:
                checkList[i] += 1
        return numberOfOperations