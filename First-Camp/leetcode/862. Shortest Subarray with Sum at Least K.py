class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        shortestLen = float('inf')
        prefix = list(accumulate(nums, initial=0))
        startPts = deque()

        for index, value in enumerate(prefix):
            while startPts and value - prefix[startPts[0]] >= k:
                shortestLen = min(shortestLen, index - startPts.popleft())
            while startPts and value <= prefix[startPts[-1]]:
                startPts.pop()
            startPts.append(index)
        return shortestLen if shortestLen != float('inf') else -1