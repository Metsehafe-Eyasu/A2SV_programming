class Solution:
    def compress(self, chars: list[str]) -> int:
        length = len(chars)
        initial = chars[0]
        index = 0
        count = 0
        for i in range(length + 1):
            if i < length and initial == chars[i]:
                count += 1
            else:
                chars[index] = initial
                index += 1

                if i < length:
                    initial = chars[i]
                
                if count > 1:
                    for j in [*str(count)]:
                        chars[index] = j
                        index += 1
                count = 1
        print(chars)
        for k in range(length-index):
            chars.pop()
        print(chars)
        return len(chars)

            
ans = Solution()
chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
ans.compress(chars)