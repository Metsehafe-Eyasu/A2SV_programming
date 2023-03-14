def intInput(): return int(input())
def intList(): return list(map(int, input().split()))
def strInput(): return input()


def solution():
    days, assistants = intList()
    prefix = [0]*(days + 2)
    for _ in range(assistants):
        start, end = intList()
        prefix[start + 1] += 1
        prefix[end + 2] -= 1
    for i in range(1, days+2):
        prefix[i] = prefix[i-1] + prefix[i]
    for i in prefix[1:days+1]:
        if i == 0:
            return 'YES'
    return 'NO'




# cases = intInput()
cases = 1
for i in range(cases):
    print(solution())