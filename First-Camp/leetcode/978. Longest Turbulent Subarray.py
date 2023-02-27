class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        length = len(arr)
        if length == 1:
            return 1
        if length == 2:
            if arr[0] == arr[1]:
                return 1
            return 2

        right = 0
        maxLen = -float('inf')

        turb = False
        if arr[0] > arr[1]:
            turb = True

        for i in range(1, length):
            if (turb and arr[i-1] < arr[i]) or (not turb and arr[i-1] > arr[i]):
                right = i - 1
                turb = not turb
            elif arr[i] == arr[i-1]:
                right = i
                if i != length-1:
                    if arr[i] > arr[i+1]:
                        turb = False
                    else:
                        turb = True
            maxLen = max(maxLen, i - right + 1)
            turb = not turb
        return maxLen