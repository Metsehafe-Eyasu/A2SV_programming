def intInput(): return int(input())
def intList(): return list(map(int, input().split()))
def strInput(): return input()


def solution():
    total, limit, row = intList()
    emotes = sorted(intList(), reverse=True)
    
    batch_len = row + 1
    batch = emotes[0]*row + emotes[1]
    
    possible = batch * (limit // batch_len)
    remaining_len = limit % batch_len
    
    remaining = emotes[0]*remaining_len

    return possible + remaining


# cases = intInput()
cases = 1
for i in range(cases):
    print(solution())
