class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        length = len(fruits)
        window = [0]*length
        count = 0
        left = 0
        maxLen = 0
        for i in range(length):
            if window[fruits[i]] == 0:
                count += 1

            window[fruits[i]] += 1
                
            while count > 2:
                window[fruits[left]] -= 1
                if window[fruits[left]] == 0:
                    count -= 1
                left += 1
                
            if count <= 2:
                maxLen = max(maxLen, i - left + 1)

        return maxLen