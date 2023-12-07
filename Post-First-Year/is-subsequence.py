class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        checker = 0
        n, m = len(s), len(t)
        for i in range(m):
            if checker == n:
                break
            if s[checker] == t[i]:
                checker += 1
        return checker == n