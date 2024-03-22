from collections import defaultdict, deque
import heapq
import math
import itertools
import sys
import bisect

def I(): return int(input())
def IL(): return list(map(int, input().split()))
def S(): return input()


def solution():
    n, k = IL()
    top = k
    if n == k:
        return 0
    ans = (n-k-1)*3 + (((top*(top-1))//(2*top)) * 3) + (((top*(top-1))%(2*top)) > 0)
    return ans + 1



cases = 1
cases = I()
for i in range(cases):
    print(solution())