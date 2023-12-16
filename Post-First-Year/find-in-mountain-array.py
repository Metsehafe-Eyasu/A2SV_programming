# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        n = mountain_arr.length()
        left = 0
        right = n - 1
        while left < right:
            mid = left + (right - left)//2
            if mountain_arr.get(mid) > mountain_arr.get(mid+1):
                right = mid
            else:
                left = mid + 1

        peak = left
        left, right = 0, peak
        while left < right:
            mid = left + (right - left)//2
            val = mountain_arr.get(mid)
            if val == target:
                return mid
            elif val > target:
                right = mid
            else:
                left = mid + 1

        left, right = peak, n-1
        while left < right:
            mid = left + (right - left)//2
            val = mountain_arr.get(mid)
            if val == target:
                return mid
            elif val > target:
                left = mid + 1
            else:
                right = mid - 1
        if mountain_arr.get(right) == target:
            return right
        return -1