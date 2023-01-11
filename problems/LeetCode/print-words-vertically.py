class Solution:
    def printVertically(self, s: str) -> List[str]:
        stringList = s.split()
        stack = max(*[len(i) for i in stringList])

        finalList = []

        for horizontal in range(stack):
            vertical = []
            for word in stringList:
                if horizontal >= len(word):
                    vertical.append(' ')
                else:
                    vertical.append(word[horizontal])
            finalList.append(vertical)

        answer = []
        for vWord in finalList:
            word = ''.join(vWord)
            strippedWord = word.rstrip()
            answer.append(strippedWord)

        return answer