class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        length = len(grid[0])
        suffix = list(accumulate(reversed(grid[0]), initial=0))
        prefix = list(accumulate(grid[1], initial=0))
        suffix.append(0)
        prefix.append(0)
        curr = 0
        minVal = float('inf')
        for i in range(1, length+1):
            curr = max(suffix[length - i], prefix[i-1])
            minVal = min(minVal, curr)
        return minVal
