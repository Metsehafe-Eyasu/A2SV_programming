class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        i = 0
        temp = len(arr)
        while i < temp:
            if arr[i] == 0:
                arr.pop()
                arr[i:i] = [0]
                i += 1
            i += 1
            if i > temp:
                break