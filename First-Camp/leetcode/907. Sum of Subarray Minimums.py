class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        stack = []
        result = 0
        arr.append(0)
        length = len(arr)

        for right in range(length):
            while stack and arr[stack[-1]] > arr[right]:
                middle = stack.pop()
                left = stack[-1] if stack else -1
                result += arr[middle] * (right - middle) * (middle - left) 

            stack.append(right)

        return result%(10**9 + 7)