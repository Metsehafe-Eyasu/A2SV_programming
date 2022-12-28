class Solution:
    def similarPairs(self, words: List[str]) -> int:
        ls = list(map(set, words))
        pair = 0
        length = len(ls)
        for i in range(length-1):
            for j in range(i+1, length):
                diff = len(ls[i].difference(ls[j])) + len(ls[j].difference(ls[i]))
                if diff == 0:
                    pair += 1
        return pair