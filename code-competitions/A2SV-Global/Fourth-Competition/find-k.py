cases = int(input())
for _ in range(cases):
    n, k = list(map(int, input().split()))
    numbers = list(map(int, input().split()))
    numbers.sort()
    sumTotal = sum(numbers)
    deducted = 0
    for i in range(n-1):
        print('asdfa')
        deducted += numbers[i]-deducted
        print('>', deducted)
        sumTotal -= (n-i)*(numbers[i] - deducted)
        print(sumTotal)
        