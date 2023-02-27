class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        ops = set(['+', '-', '*', '/'])
        for i in tokens:
            if i in ops:
                right = int(stack.pop())
                left = int(stack.pop())
                carry = 0
                if i == '+': carry = left + right
                elif i == '-': carry = left - right
                elif i == '*': carry = left * right
                elif i == '/': carry = trunc(left / right)
                stack.append(carry)
            else:
                stack.append(i)
        return int(stack[0])