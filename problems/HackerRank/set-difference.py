# Enter your code here. Read input from STDIN. Print output to STDOUT
englishNum = int(input())
englishIDs = set(map(int, input().split()))

frenchNum = int(input())
frenchIDs = set(map(int, input().split()))

diff = englishIDs.difference(frenchIDs)
print(len(diff))