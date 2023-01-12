from collections import defaultdict
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        reverse = False
        zigzag = defaultdict(str)
        current = 0
        for i in s:
            zigzag[current] += i
            if reverse:
                current -=1
            else:
                current += 1
            
            if current == 0:
                reverse = False
            elif current == numRows - 1:
                reverse = True
                
        answer = ''
        length = len(zigzag)
        for i in range(length):
            answer += zigzag[i]
        return answer