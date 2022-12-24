class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 1:
            return strs[0]
        strs.sort()
        first = strs[0]
        last = strs[-1]
        commonPrefix = ""
        length = len(first)
        for i in range(length):
            if first[i] == last[i]:
                commonPrefix += first[i]
            else:
                break
        return commonPrefix