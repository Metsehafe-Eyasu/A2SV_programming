class Solution:
    def hIndex(self, citations: List[int]) -> int:
        length = len(citations)
        left, right = 0, length - 1
        while left < right:
            mid = left + (right - left)//2
            if citations[mid] >= length - mid:
                right = mid
            else:
                left = mid + 1
        return length - left if citations[left] >= length - left else 0