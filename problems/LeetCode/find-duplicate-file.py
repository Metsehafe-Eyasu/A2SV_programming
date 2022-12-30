from collections import defaultdict
class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        ls = []
        for i in paths:
            inList = i.split()
            ls.append(inList)

        pathDict = defaultdict(list)

        for i in ls:
            length = len(i)
            ind = 1
            while ind < length:
                start = i[ind].index('(') + 1
                end = len(i[ind]) - 1
                key = i[ind][start:end]
                pathDict[key].append(i[0] + '/' + i[ind][:start - 1])
                ind+=1

        ls.clear()
        for key, val in pathDict.items():
            if len(val) > 1:
                ls.append(val)
        return ls