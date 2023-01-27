class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        answer = 0
        piles.sort(reverse=True)
        length = len(piles)
        print(piles)
        i = 1
        while i < length:
            answer += piles[i]
            length -= 1
            i += 2
        return answer
