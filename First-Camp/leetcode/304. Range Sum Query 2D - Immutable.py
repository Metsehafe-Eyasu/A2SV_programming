class NumMatrix:
    prefix_sum = []
    def __init__(self, matrix: List[List[int]]):
        rows = len(matrix)
        cols = len(matrix[0])
        self.prefix_sum = [[0]*(cols + 1) for _ in range(rows+1)]
        for i in range(rows):
            for j in range(cols):
                self.prefix_sum[i+1][j+1] = self.prefix_sum[i][j+1] + \
                                       self.prefix_sum[i+1][j] - \
                                       self.prefix_sum[i][j] + \
                                       matrix[i][j]


    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.prefix_sum[row2+1][col2+1] - \
               self.prefix_sum[row2+1][col1] - \
               self.prefix_sum[row1][col2+1] + \
               self.prefix_sum[row1][col1] 


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)