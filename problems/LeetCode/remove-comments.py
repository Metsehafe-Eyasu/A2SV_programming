class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        sourceString = '\n'.join(source)
        length = len(sourceString)

        finalAnswer = ''
        i = 0
        while i < length:
            string = sourceString[i:i+2]
            if string == '//':
                i += 2
                while i < length and sourceString[i] != '\n':
                    i += 1
            elif string == '/*':
                i += 2
                while sourceString[i:i+2] != '*/':
                    i += 1
                i += 2
            else:
                finalAnswer += sourceString[i]
                i += 1

        answerList = finalAnswer.split('\n')

        finalList = []
        for i in answerList:
            if i != '':
                finalList.append(i)
        return finalList