class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        stack = []
        spacesSet = set(spaces)
        length = len(s)
        for index in range(length):
            if index in spacesSet:
                stack.append(' ')
            stack.append(s[index])
        return ''.join(stack)
