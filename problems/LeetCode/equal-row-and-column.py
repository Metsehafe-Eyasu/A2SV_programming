from collections import Counter
class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        length = len(grid)
        colSum = [[] for _ in range(length)]
        rowSum = [[] for _ in range(length)]
        for i in range(length):
            for j in range(length):
                colSum[i].append(grid[i][j])
                rowSum[j].append(grid[i][j])

        colList = Counter(map(tuple, colSum))
        rowList = Counter(map(tuple, rowSum))

        answer = 0
        for i in colList:
            if i in rowList:
                answer += colList[i]*rowList[i]
        return answer