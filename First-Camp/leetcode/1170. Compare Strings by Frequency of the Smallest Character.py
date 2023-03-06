class Solution:
    def smallestCharFreq(self, word: str) -> int:
        char = word[0]
        count = 1
        length = len(word)
        for i in range(1, length):
            if word[i] < char:
                char = word[i]
                count = 1
            elif word[i] == char:
                count += 1
        return count

    def binarySearch(self, arr: List[int], target: int) -> int:
        left = 0
        right = len(arr)
        while left < right:
            mid = left + (right - left) // 2
            if arr[mid] >= target:
                right = mid
            else:
                left = mid + 1
        return left


    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        freqList = sorted([self.smallestCharFreq(word) for word in words])
        answer = []
        for query in queries:
            count = self.smallestCharFreq(query)
            answer.append(len(words) - self.binarySearch(freqList, count+1))
        
        return answer
