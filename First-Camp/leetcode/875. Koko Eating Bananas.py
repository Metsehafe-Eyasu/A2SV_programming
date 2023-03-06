class Solution:
    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        def feasible(speed) -> bool:
            return sum(ceil(pile / speed) for pile in piles) <= H

        left, right = 1, max(piles)
        while left < right:
            mid = left  + (right - left) // 2
            if feasible(mid):
                right = mid
            else:
                left = mid + 1
        return left