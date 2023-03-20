def intInput(): return int(input())
def intList(): return list(map(int, input().split()))
def strInput(): return input()
 
 
def solution():
    total, oppPower = intList()
    candidates = sorted(intList(), reverse=True)
    
    wins = 0
    count = total
    for left in range(total):
        if count >= (oppPower//candidates[left]) + 1:
            wins += 1
            count -= (oppPower//candidates[left]) + 1
    return wins
 
# cases = intInput()
cases = 1
for i in range(cases):
    print(solution())
