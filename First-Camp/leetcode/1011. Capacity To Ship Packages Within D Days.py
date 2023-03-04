class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        maxLoad = max(weights)
        total = sum(weights)
        l, r = maxLoad, total
        while l < r:
            mid = l + (r - l) // 2
            daysNeeded = 1
            current = 0
            for i in weights:
                current += i
                if current > mid:
                    daysNeeded += 1
                    current = i
            if daysNeeded <= days:
                r = mid
            else:
                l = mid + 1
        return l