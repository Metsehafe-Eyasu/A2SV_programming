class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        magic = set([i for i in range(1, 10)])
        rows = len(grid)
        cols = len(grid[0])
        count = 0
        if rows < 3 or cols < 3:
            return 0
        for i in range(rows-2):
            for j in range(cols-2):
                box = set()
                diagonals = [0, 0]
                rowSum = [0 for _ in range(3)]
                colSum = [0 for _ in range(3)]
                for k in range(i, i+3):
                    boxRow = grid[k][j:j+3]
                    box.update(boxRow)                
                    for l in range(j, j+3):
                        rowSum[k-i] += grid[k][l]
                        colSum[j-l] += grid[k][l]
                        if k+l == i+j+2:
                            diagonals[0]+= grid[k][l]
                        if k-l == i-j:
                            diagonals[1]+= grid[k][l]
                            
                if box != magic:
                    continue
                answer = set()
                answer.update(rowSum, colSum, rowSum, diagonals)
                if len(answer) == 1:
                    count+=1
        return count