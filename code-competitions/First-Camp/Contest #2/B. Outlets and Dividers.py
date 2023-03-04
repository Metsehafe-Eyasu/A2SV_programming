cases = int(input())
for _ in range(cases):
    students, dividers = list(map(int, input().split()))
    divList = list(map(int, input().split()))
    divList.sort(reverse=True)
    available = 2
    needed = 0
    if available >= students:
        print(needed)
    else: 
        for divider in divList:
            available += divider - 1
            needed += 1
            if available >= students:
                print(needed)
                break
        print(-1)
    