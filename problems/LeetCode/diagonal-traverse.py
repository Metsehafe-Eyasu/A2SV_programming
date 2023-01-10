from collections import defaultdict
class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        answer = defaultdict(list)
        rowLength = len(mat)
        colLength = len(mat[0])

        for i in range(rowLength):
            for j in range(colLength):
                answer[i+j].append(mat[i][j])

        ansList = []
        for i in answer:
            if i%2 == 0:
                reversedList = reversed(answer[i])
                ansList.extend(reversedList)
            else:
                ansList.extend(answer[i])
                
        return ansList