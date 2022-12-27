class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        list1 = []
        for i in s:
            list1.append(i)
        list1.sort()
        list2 = []
        for i in t:
            list2.append(i)
        list2.sort()
        x = 0 
        length = len(list1)
        for i in range(length):
            if list1[i] != list2[i]:
                return (list2[i])
        return (list2[len(list2) - 1])