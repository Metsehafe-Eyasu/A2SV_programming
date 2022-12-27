class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        i = 0
        w1Len = len(word1)
        w2Len = len(word2)
        stack = ''

        while i < w1Len and i < w2Len:
            stack += word1[i]
            stack += word2[i]
            i += 1
        if i < w1Len:
            stack += word1[i:]
        if i < w2Len:
            stack += word2[i:]
        return stack