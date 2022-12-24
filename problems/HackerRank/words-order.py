# Enter your code here. Read input from STDIN. Print output to STDOUT
totalWords = int(input())
wordsDict = {}
for i in range(totalWords):
    word = input()
    if word in wordsDict:
        wordsDict[word] += 1
    else:
        wordsDict[word] = 1
        
print(len(wordsDict))

for key in wordsDict:
    print(wordsDict[key], end=' ')