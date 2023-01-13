class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        side = len(matrix)

        for i in range(side):
            for j in range(i, side):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
            
        for i in range(side):
            left = 0
            right = side - 1
            while left < right:
                matrix[i][left], matrix[i][right] = matrix[i][right], matrix[i][left]
                left += 1
                right -= 1