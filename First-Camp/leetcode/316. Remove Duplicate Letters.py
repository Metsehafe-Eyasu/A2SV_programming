class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        # s = [*s]
        visited = dict()
        seen =set()
        stack = []
        for index, char in enumerate(s):
            visited[char] = index
        
        for index, char in enumerate(s):
            if char in seen: continue
            while stack and stack[-1] > char and index < visited[stack[-1]]:
                seen.remove(stack.pop())
            stack.append(char)
            seen.add(char)
        return ''.join(stack)