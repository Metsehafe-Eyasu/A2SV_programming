# Enter your code here. Read input from STDIN. Print output to STDOUT
testCases = int(input())
for test in range(testCases):
    numberOfCubes = int(input())
    cubesList = list(map(int, input().split()))
    left = 0
    right = numberOfCubes - 1
    lastStack = float("inf")
    checker = 'Yes'
    while left <= right:
        if cubesList[left] >= cubesList[right] and cubesList[left] <= lastStack:
            lastStack = cubesList[left]
            left += 1
        elif cubesList[right] > cubesList[left] and cubesList[right] <= lastStack:
            lastStack = cubesList[right]            
            right -= 1
        else:
            checker = 'No'
            break
    print(checker)