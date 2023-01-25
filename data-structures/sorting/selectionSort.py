#User function Template for python3

class Solution: 
    def select(self, arr, i):
        # code here 
        length = len(arr)
        minInd = i 
        for index in range(i+1, length):
            if arr[index] < arr[minInd]:
                minInd = index
        return minInd
    
    def selectionSort(self, arr,n):
        #code here
        for i in range(n-1):
            selectedIndex = self.select(arr, i)
            arr[i], arr[selectedIndex] = arr[selectedIndex], arr[i]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        Solution().selectionSort(arr, n)
        for i in range(n):
            print(arr[i],end=" ")
        print()
# } Driver Code Ends