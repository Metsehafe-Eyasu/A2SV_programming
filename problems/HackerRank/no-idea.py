# Enter your code here. Read input from STDIN. Print output to STDOUT
generalSize, disjointSize = list(map(int, input().split(' ')))
generalList = list(input().split(' '))

happy = set(input().split(' '))
sad = set(input().split(' '))

totalHappiness = 0

for checker in range(generalSize):
    if generalList[checker] in happy:
        totalHappiness += 1
    elif generalList[checker] in sad:
        totalHappiness -= 1

print(totalHappiness)