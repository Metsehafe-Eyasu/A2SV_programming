from collections import Counter
class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        winners = []
        losers = []
        answerList = []

        for i in matches:
            winners.append(i[0])
            losers.append(i[1])

        a = Counter(winners)
        b = Counter(losers)

        aKeys = set(a.keys())
        bKeys = set(b.keys())
        noLoss = list(aKeys.difference(bKeys))
        noLoss.sort()
        answerList.append(noLoss)
        

        arr = []
        for key, value in b.items():
            if value == 1:
                arr.append(key)
        arr.sort()
        answerList.append(arr)


        return (answerList)