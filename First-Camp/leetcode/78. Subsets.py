class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = [[]]
        path = []
        def backtrack(index):            
            if index >= len(nums):
                return

            path.append(nums[index])
            ans.append(path[:])

            backtrack(index + 1)
            path.pop()
            backtrack(index + 1)
        
        backtrack(0)
        return ans