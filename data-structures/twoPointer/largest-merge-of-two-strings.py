class Solution:
    def largestMerge(self, word1: str, word2: str) -> str:
        length1 = len(word1)
        length2 = len(word2)
        
        answer = []
        while length1 > 0 and length2 > 0:
            if word1 >= word2:
                answer.append(word1[0])
                word1 = word1[1:]
                length1 -= 1
            else:
                answer.append(word2[0])
                word2 = word2[1:]
                length2 -= 1
        
        if length2 > 0:
            for i in word2:
                answer.append(i)
        if length1 > 0:
            for i in word1:
                answer.append(i)
                
        return "".join(answer)