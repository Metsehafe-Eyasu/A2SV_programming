def intInput(): return int(input())
def intList(): return list(map(int, input().split()))
def strInput(): return input()
 
LIMIT = 2**32 - 1
 
def solution():
    answer = 0
    stack = [[1, 0]]
    curr = 1
    
    lines = intInput()
    for _ in range(lines):
        line = strInput()
        if line == 'add':
            stack[-1][1] += 1
        elif line == 'end':
            iter, add = stack.pop()
            stack[-1][1] += iter*add
        else:
            word, iter = line.split()
            stack.append([int(iter), 0])
    if stack[-1][1] > LIMIT:
        return "OVERFLOW!!!"
    else:
        return stack[-1][1]
 
# cases = intInput()
cases = 1
for i in range(cases):
    print(solution())