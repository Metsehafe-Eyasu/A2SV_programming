class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = set()
        cols = set()

        rowSpan = len(matrix)
        colSpan = len(matrix[0])

        for i in range(rowSpan):
            for j in range(colSpan):
                if matrix[i][j] == 0:
                    rows.add(i)
                    cols.add(j)
        for i in rows:
            for j in range(colSpan):
                matrix[i][j] = 0
        for i in cols:
            for j in range(rowSpan):
                matrix[j][i] = 0