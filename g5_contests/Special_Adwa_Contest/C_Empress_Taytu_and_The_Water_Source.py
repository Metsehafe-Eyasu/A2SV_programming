from collections import defaultdict, deque
import heapq
import math
import itertools
import sys
import bisect

def I(): return int(input())
def IL(): return list(map(int, input().split()))
def S(): return input()

def feasible(tank, demand, pos, k):
    time = 0
    for i in range(len(demand)):
        time += 2 * ((demand[i] + tank - 1)//tank) * pos[i] + (2*((demand[i] + tank - 1)//tank))
    return time <= k

def solution():
    n, k = IL()
    demand = IL()
    pos = IL()
    
    l, r = 1, sum(demand)
    
    while l < r:
        mid = (l+r)//2
        if feasible(mid, demand, pos, k):
            r = mid
        else:
            l = mid + 1
    return l if feasible(l, demand, pos, k) else -1




cases = I()
# cases = 1
for i in range(cases):
    print(solution())