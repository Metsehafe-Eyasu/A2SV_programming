from collections import defaultdict
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        length = len(s)
        windowLen = len(p)

        if(length < windowLen):
            return []
        
        comp = defaultdict(int)
        window = defaultdict(int)
        for i in range(windowLen):
            window[s[i]] += 1
            comp[p[i]] += 1

        endIndex = windowLen
        startIndex = 0

        count = []
        while endIndex <= length:
            if comp == window:
                count.append(startIndex)
            
            if window[s[startIndex]] > 1:
                window[s[startIndex]] -= 1
            else:
                window.pop(s[startIndex])
            if(endIndex == length):
                break
            
            window[s[endIndex]] += 1
            
            endIndex += 1
            startIndex += 1
        return count
            