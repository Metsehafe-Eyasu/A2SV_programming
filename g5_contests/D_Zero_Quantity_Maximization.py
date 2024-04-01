from collections import defaultdict, deque, Counter
import heapq
import math
import itertools
import sys
import bisect

def I(): return int(input())
def IL(): return list(map(int, input().split()))
def S(): return input()


def solution():
    n = I()
    a = IL()
    b = IL()
    result = 0
    cnt = defaultdict(int)
    for i in range(n):
        if a[i] == 0 and b[i] == 0:
            result += 1
        elif a[i] == 0:
            continue
        elif b[i] == 0:
            cnt[(0, 1)]+=1
        else:
            if a[i] < 0:
                a[i]*=-1
                b[i]*=-1
            fac = math.gcd(abs(a[i]), abs(b[i]))
            a[i]//=fac
            b[i]//=fac
            cnt[(a[i], b[i])] += 1
    added = 0
    for key, val in cnt:
        added = max(added, val)
    return result + added

cases = 1
# cases = I()
for i in range(cases):
    print(solution())