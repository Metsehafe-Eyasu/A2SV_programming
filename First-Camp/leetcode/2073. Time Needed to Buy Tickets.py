class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        selected = tickets[k]
        timeTaken = 0
        for index, value in enumerate(tickets):
            if index <= k:
                timeTaken += min(selected, value)
            else:
                timeTaken += min(selected-1, value)
        return timeTaken