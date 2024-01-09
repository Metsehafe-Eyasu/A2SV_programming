def intInput(): return int(input())
def intList(): return list(map(int, input().split()))
def strInput(): return input()


def solution():
    n = intInput()
    word = strInput()
    ptr = 0
    result = ''
    while ptr < n:
        runner = ptr + 1
        while runner < n and word[runner] != word[ptr]:
            runner += 1
        
        result += word[ptr]
        if runner < n:
          ptr = runner
        ptr += 1
    return result




cases = intInput()
# cases = 1
for i in range(cases):
    print(solution())