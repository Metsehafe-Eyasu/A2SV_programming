class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        prefix = [0]*1003
        maxIndex = 0
        for noOfPass, start, end in trips:
            prefix[start+1] += noOfPass
            prefix[end+1] -= noOfPass
            maxIndex = max(maxIndex, end+1)
        for i in range(1, 1003):
            prefix[i] += prefix[i-1]
        
        for i in range(1, maxIndex):
            if prefix[i] > capacity:
                return False
        return True