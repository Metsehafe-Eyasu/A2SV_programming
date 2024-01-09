def intInput(): return int(input())
def intList(): return list(map(int, input().split()))
def strInput(): return input()


def solution():
    val = intInput()
    if val < 1400:
      return 'Division 4'
    elif val < 1600:
      return 'Division 3'
    elif val < 1900:
      return 'Division 2'
    else:
      return 'Division 1'


cases = intInput()
# cases = 1
for i in range(cases):
    print(solution())