class Solution:
    def freqAlphabets(self, s: str) -> str:
        word = 'abcdefghijklmnopqrstuvwxyz'
        stack = []
        
        for num in s:
            if num == '#':
                d1 = stack.pop()
                d2 = stack.pop()
                index = d2*10+d1
                stack.append(index)
            else:
                stack.append(int(num))
                
        tWord = ''
        for i in stack:
            tWord += word[i - 1]
            
        return tWord