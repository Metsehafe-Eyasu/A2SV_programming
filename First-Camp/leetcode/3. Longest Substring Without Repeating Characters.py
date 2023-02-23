class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxLen = 1
        unique = set()
        start = 0
        length = len(s)
        if length == 0:
            return 0
        for i in range(length):
            while s[i] in unique:
                unique.remove(s[start])
                start += 1
            unique.add(s[i])
            maxLen = max(len(unique), maxLen)
        
        return maxLen
