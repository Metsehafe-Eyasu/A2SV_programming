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
    s = S()
    check = True
    cnt = Counter(s)
    if len(cnt) == 1:
        return -1
    n = len(s)
    for i in range(n//2):
        if s[i] != s[n-i-1]:
            break
    else:
        return n-1
    return n

cases = 1
cases = I()
for i in range(cases):
    print(solution())