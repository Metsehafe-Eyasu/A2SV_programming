class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        maxIndex = arr.index(max(arr))
        left = maxIndex-1
        right = maxIndex+1

        length = len(arr)
        if length < 3:
            return False

        if arr[maxIndex] == arr[0] or arr[maxIndex] == arr[length-1]:
            return False
            
        while left > -1:
            if arr[left] >= arr[left+1]:
                return False
            left -= 1

        while right < length:
            if arr[right] >= arr[right-1]:
                return False
            right += 1

        return True