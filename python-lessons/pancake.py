class Solution:
    def pancakeSort(self, A):
        res = []
        for x in range(len(A), 1, -1):
            i = A.index(x)
            res.extend([i + 1, x])
            print(A)
            A = A[:i:-1] + A[:i]
            print(A)
        return res
array = [3, 2, 1, 4]
ans = Solution()
print(ans.pancakeSort(array))