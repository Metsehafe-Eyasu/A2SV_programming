class Solution:
    def partitionLabels(self, s: str) -> list[int]:
        length = len(s)
        lastOccur = {char: index for index, char in enumerate(s)}
        current = 0
        answer = []

        while current < length:
            end = lastOccur[s[current]]
            j = current+1
            while j < end:
                if lastOccur[s[j]] > end:
                    end = lastOccur[s[j]]
                j += 1
            answer.append(end-current + 1)
            current = end + 1   

        return answer