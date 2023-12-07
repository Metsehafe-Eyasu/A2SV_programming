class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        memo = {}
        def dp(n):
            if n == 1:
                return 1
            if n not in memo:
                if n%2:
                    memo[n] = dp(3*n + 1) + 1
                else:
                    memo[n] = dp(n/2) + 1
            return memo[n]
        nums = [i for i in range(lo, hi+1)]
        ans = [0 for i in range(lo, hi+1)]
        for i in range(len(nums)):
            ans[i] = dp(nums[i])
        paired = list(zip(ans,nums))
        paired.sort()
        return paired[k-1][1]
        