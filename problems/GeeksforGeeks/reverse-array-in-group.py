class Solution:
    # Function to reverse every sub-array group of size k.
    def reverseInGroups(self, arr, N, K):
        cycles = (N // K) + 1
        for i in range(cycles):
            start = i * K
            end = start + K
            temp = arr[start:end]
            temp.reverse()
            arr[start:end] = temp
