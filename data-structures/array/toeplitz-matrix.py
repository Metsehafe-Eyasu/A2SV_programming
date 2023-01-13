from collections import defaultdict
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        toeplitz = defaultdict(set)

        row = len(matrix)
        col = len(matrix[0])

        for i in range(row):
            for j in range(col):
                toeplitz[i - j].add(matrix[i][j])
                if len(toeplitz[i-j]) > 1:
                    return False
        return True