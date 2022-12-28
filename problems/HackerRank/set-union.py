# Enter your code here. Read input from STDIN. Print output to STDOUT
englishTotal = int(input())
englishRolls = set(map(int, input().split()))

frenchTotal = int(input())
frenchRolls = set(map(int, input().split()))

union = frenchRolls.union(englishRolls)

print(len(union))