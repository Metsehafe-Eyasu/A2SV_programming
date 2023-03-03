class Solution:
    def reversed(self, s: str) -> str:
        return s[::-1]
    def invert(self, s: str) -> str:
        ans = []
        for i in s:
            if i == '0':
                ans.append('1')
            else:
                ans.append('0')
        return ''.join(ans)
    def findVal(self, n: int, s: str) -> str:
        if n == 1: 
            return s + '0'

        prev = self.findVal(n-1, s)
        inv = self.invert(prev)
        rev = self.reversed(inv)
        return prev + '1' + rev
    def findKthBit(self, n: int, k: int) -> str:
        answer = self.findVal(n, "")
        return answer[k-1]
