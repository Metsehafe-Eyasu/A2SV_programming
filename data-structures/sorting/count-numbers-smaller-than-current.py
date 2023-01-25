class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        length = len(nums)
        answer = []
        for i in range(length):
            count = 0
            for j in range(length):
                if i == j:
                    continue
                if nums[i] > nums[j]:
                    count += 1
            answer.append(count)
        return answer