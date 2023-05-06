class Solution:
    def children(self, current):
        return [2*current + 1, 2*current + 2]

    def swap(self, arr, l, r):
        arr[l], arr[r] = arr[r], arr[l]
    # Heapify function to maintain heap property.

    def heapify(self, arr, n, i):
        # code here
        maxVal = i
        l, r = self.children(i)
        if l < n and arr[l] > arr[maxVal]:
            maxVal = l
        if r < n and arr[r] > arr[maxVal]:
            maxVal = r

        if maxVal != i:
            self.swap(arr, maxVal, i)
            self.heapify(arr, n, maxVal)

    # Function to build a Heap from array.
    def buildHeap(self, arr, n):
        # code here
        pt = n//2 - 1
        for i in range(pt, -1, -1):
            self.heapify(arr, n, i)

    # Function to sort an array using Heap Sort.

    def HeapSort(self, arr, n):
        # code here
        self.buildHeap(arr, n)
        for i in range(n-1, 0, -1):
            self.swap(arr, 0, i)
            self.heapify(arr, i, 0)
