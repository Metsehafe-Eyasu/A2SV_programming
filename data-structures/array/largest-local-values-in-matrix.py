class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        side = len(grid)
        answer = [[] for _ in range(side-2)]
        for i in range(side-2):
            for j in range(side-2):
                maxBox = 0
                for row in range(i, i+3):
                    rowMax = max(grid[row][j:j+3])
                    maxBox = max(rowMax, maxBox)
                answer[i].append(maxBox)
        return answer