class Solution:
    def noConflict(self, queens, current):
        for i in range(current):
            if queens[i] == queens[current]: 
                return False
            if current-i == abs(queens[current]-queens[i]):
                return False
        return True

    def fillGrid(self, queens):
        grid = []
        for val in queens:
            row = ""
            for i in range(len(queens)):
                if i == val:
                    row += 'Q'
                else: 
                    row += '.'
            grid.append(row)
        return grid
        
    def solveNQueens(self, n: int) -> List[List[str]]:
        queens = [-1]*n
        ans = []
        def backtrack(current):
            if current == n:
                ans.append(self.fillGrid(queens))
                return
            for i in range(n):
                queens[current] = i
                if self.noConflict(queens, current):
                    backtrack(current+1)
        backtrack(0)
        return ans
        
            
        