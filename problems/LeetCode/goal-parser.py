class Solution:
    def interpret(self, command: str) -> str:
        length = len(command)
        stack = ''

        for i in range(length):
            if (command[i] == 'G'):
                stack += 'G'
            elif command[i] == '(' and command[i + 1] == ')':
                stack += 'o'
                i += 1
            elif command[i] == '(' and command[i+1] == 'a':
                stack += 'al'
                i += 3
        return stack