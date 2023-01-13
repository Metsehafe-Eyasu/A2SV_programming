class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row = len(matrix)
        col = len(matrix[0])

        if target < matrix[0][0] or target > matrix[row-1][col-1]:
            return False
            
        searchRow = matrix[row-1]

        for i in range(row):
            if matrix[i][0] > target:
                searchRow = matrix[i-1]
                break

        for i in searchRow:
            if i == target:
                return True
        return False