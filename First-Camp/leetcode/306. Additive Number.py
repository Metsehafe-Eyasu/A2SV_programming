class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        current = []

        def backtrack(index):
            if index >= len(num):
                return len(current) >= 3
            
            for i in range(index, len(num)):
                word = str(num[index:i+1])
                val = int(word)
                if val < 10**(len(word)-1) and len(word) > 1:
                    return
                if len(current) <= 1 or val == current[-2] + current[-1]:
                    current.append(val)
                    if backtrack(i + 1):
                        return True
                    current.pop()
            return False

        return backtrack(0)