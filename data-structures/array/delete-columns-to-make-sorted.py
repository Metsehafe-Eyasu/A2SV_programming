class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        rowLen = len(strs)
        colLen = len(strs[0])

        deletedCols = 0
        for i in range(colLen):
            word = []
            for j in range(rowLen):
                word.append(strs[j][i])
            sortedWord = sorted(word)
            if word != sortedWord:
                deletedCols += 1
        return deletedCols