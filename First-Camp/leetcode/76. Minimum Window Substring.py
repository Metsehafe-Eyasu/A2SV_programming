class Solution:
    def minWindow(self, s: str, t: str) -> str:
        length = len(s)
        window = [0]*128
        for i in t:
            window[ord(i)] += 1

        right = left = start = 0
        required = len(t)
        minSize = float('inf')
        
        for right in range(length):
            if window[ord(s[right])] > 0:
                required -= 1
            
            window[ord(s[right])] -= 1
            while required == 0:
                if right - left < minSize:
                    start = left
                    minSize = right - left

                window[ord(s[left])] += 1
                if window[ord(s[left])] > 0:
                    required += 1
                left += 1
        return s[start:start+minSize+1] if minSize != float('inf') else ""