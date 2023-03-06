class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        def isRight(index: int) -> bool:
            right = index + 1
            if arr[right] < arr[index]:
                return True
            return False
            
        length = len(arr)
        left = 1
        right = len(arr) - 2
        while left < right:
            mid = left + (right - left) // 2
            if isRight(mid):
                right = mid
            else:
                left = mid + 1

        return left