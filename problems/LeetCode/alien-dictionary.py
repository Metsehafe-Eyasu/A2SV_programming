class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        order_map = {}
        for index, val in enumerate(order):
            order_map[val] = index
        totalLength = len(words) - 1
        for i in range(totalLength):
            wordLength = len(words[i])
            for j in range(wordLength):
                if j >= len(words[i + 1]): 
                    return False
                
                if words[i][j] != words[i+1][j]:
                    if order_map[words[i][j]] > order_map[words[i+1][j]]:
                        return False
                    break
        return True