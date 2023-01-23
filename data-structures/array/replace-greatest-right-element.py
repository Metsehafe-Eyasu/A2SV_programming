class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        length = len(arr)
        maxRight = []
        maxVal = 0

        for i in range(length-1, -1, -1):
            if arr[i]>=maxVal:
                maxVal = arr[i]
                maxRight.append(maxVal)

        for i in range(length-1):
            if arr[i] == maxRight[len(maxRight)-1]:
                maxRight.pop()
            arr[i] = maxRight[len(maxRight)-1]
        arr[length-1] = -1
        
        return arr
