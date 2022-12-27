class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        length = len(arr)
        for i in range(length - 1):
            for j in range(i + 1, length):
                if arr[i]/2 == arr[j] or arr[j]/2 == arr[i]:
                    return True
        return False