class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        maxCount = 0
        length = len(s)
        for i in range(length):
            count = 0
            index = i
            while index < length:
                if s[index] != s[i]:
                    count += 1

                if count > k:
                    maxCount = max(maxCount, index - i - 1)
                    break 
                index += 1
                maxCount = max(maxCount, index - i)
            
            
            ind = i - 1
            while ind > -1:
                if s[ind] != s[i]:
                    count += 1
                
                if count > k:
                    maxCount = max(maxCount, index - ind - 2)
                    break
                ind -= 1
                    
                maxCount = max(maxCount, index - ind - 1)


        return maxCount