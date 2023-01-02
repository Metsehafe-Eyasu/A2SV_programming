patternCount = int(input())
firstWord = [*input()]
length = len(firstWord)

if patternCount == 1:
    for i in range(length):
        if firstWord[i] == '?':
            firstWord[i] = 'x'

for i in range(patternCount - 1):
    string = input()
    for j in range(length):
        if firstWord[j] == '?' and string[j] == '?':
            firstWord[j] = '!'
        elif firstWord[j] == '?' or firstWord == '!' and string[j] != '?':
            firstWord[j] = string[j]
        elif firstWord[j] != '?' and string[j] == '?':
            continue
        elif firstWord[j] != string[j]:
            firstWord[j] = '#'

for i in range(length):
        if firstWord[i] == '!':
            firstWord[i] = 'x'
        elif firstWord[i] == '#':
            firstWord[i] = '?'

print(''.join(firstWord))