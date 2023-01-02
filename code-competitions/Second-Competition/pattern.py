patternCount = int(input())
words = []
for i in range(patternCount):
    words.append(input())

length = len(words)
width = len(words[0])

answer = ''

for index in range(width):
    chars = set()
    for i in range(length):
        if words[i][index] != '?':
            chars.add(words[i][index])
    if len(chars) == 0:
        answer += 'x'
    elif len(chars) == 1:
        answer += chars.pop()
    else:
        answer += '?'

print(answer)
