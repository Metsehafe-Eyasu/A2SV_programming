class Solution:
    def balancedString(self, s: str) -> int:
        dictMap = Counter(s) 
        left = 0
        ans = length = len(s)
        for right, char in enumerate(s):
            dictMap[char] -= 1
            while left < length and all(length/4 >= dictMap[c] for c in 'QWER'):
                ans = min(ans, right - left + 1)
                dictMap[s[left]] += 1
                left += 1
        return ans