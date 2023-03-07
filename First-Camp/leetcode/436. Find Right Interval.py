class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        length = len(intervals)
        startInd = sorted([[start, index] for index, [start, _] in enumerate(intervals)])
        answer = []
        for start, end in intervals:
            left, right = 0, length
            while left < right:
                mid = left + (right - left) // 2
                if startInd[mid][0] >= end:
                    right = mid
                else:
                    left = mid + 1
            if left == length: answer.append(-1)
            else: answer.append(startInd[left][1])
        return answer