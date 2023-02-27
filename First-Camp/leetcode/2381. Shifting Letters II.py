class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        string = [ord(ch) for ch in s]
        length = len(string)
        prefix = [0]*(length+2)
        
        for start, end, shift in shifts:
            if shift == 0:    
                prefix[start+1] -= 1
                if end < length:
                    prefix[end+2] += 1
            else:
                prefix[start+1] += 1
                if end < length:
                    prefix[end+2] -= 1
                
        for i in range(1, length+2):
            prefix[i] += prefix[i-1]
        
        for index, char in enumerate(string):
            string[index] = chr((((char + prefix[index+1]) - 97)%26) + 97)
            
        return "".join(string)