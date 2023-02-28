class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        stack = []
        for i in s:
            if i == '(':
                stack.append(i)
            else:
                if stack[-1] == '(':
                    stack.pop()
                    stack.append(1)
                else:
                    value = 0
                    while stack and stack[-1] != '(':
                        value += stack.pop()
                    stack.pop()
                    stack.append(2*value)
        return sum(stack)