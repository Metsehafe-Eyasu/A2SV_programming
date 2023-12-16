class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        result = [[1] for _ in range(numRows)]
        for i in range(1, numRows):
            for x in range(1, i):
                result[i].append(result[i-1][x] + result[i-1][x-1])
            result[i].append(1)
        return result
        