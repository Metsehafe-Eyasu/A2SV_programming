class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        lenRow = len(grid)
        lenCol = len(grid[0])
        rowWiseSum = [0 for _ in range(lenRow)]
        colWiseSum = [0 for _ in range(lenCol)]

        for i in range(lenRow):
            for j in range(lenCol):
                if grid[i][j] == 0:
                    rowWiseSum[i] -= 1
                else:
                    rowWiseSum[i] += 1
        for i in range(lenCol):
            for j in range(lenRow):
                if grid[j][i] == 0:
                    colWiseSum[i] -= 1
                else:
                    colWiseSum[i] += 1

        answer = [[] for i in range(lenRow)]

        for i in range(lenRow):
            for j in range(lenCol):
                net = rowWiseSum[i] + colWiseSum[j]
                answer[i].append(net)
        return answer