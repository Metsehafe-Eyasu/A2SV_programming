cases = int(input())
for _ in range(cases):
    prog, math = list(map(int, input().split()))
    print(min(min(prog, math), (prog+math)//4))