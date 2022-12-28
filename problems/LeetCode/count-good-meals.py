from collections import defaultdict
class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        powers = []
        for i in range(22):
            powers.append(2**i)

        n = defaultdict(int)
        for i in deliciousness:
            n[i] += 1
            
        finalAnswer = 0

        for key, val in n.items():
            if val > 1 and key in powers:
                finalAnswer += val * (val - 1)
            sum = 0
            for p in powers:
                curr = p - key
                if curr != key and curr in n:
                    sum += n[curr]
            finalAnswer += sum*val
        finalAnswer //= 2
        return finalAnswer % (10**9+7)
            