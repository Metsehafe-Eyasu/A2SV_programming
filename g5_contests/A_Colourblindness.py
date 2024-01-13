def intInput(): return int(input())
def intList(): return list(map(int, input().split()))
def strInput(): return input()


def solution():
    n = intInput()
    a = strInput()
    b = strInput()
    for i in range(len(a)):
        if a[i] == b[i] or (a[i] in ['G', 'B'] and b[i] in ['G', 'B']):
            continue
        return 'NO'
    return 'YES'




cases = 1
cases = intInput()
for i in range(cases):
    print(solution())