from collections import defaultdict, deque, Counter
from heapq import heapify, heappop, heappush
import math
import itertools
import sys
import bisect

def I(): return int(input())
def IL(): return list(map(int, input().split()))
def S(): return input()


def solution():
    n, m = IL()
    indegree = defaultdict(int)
    adj = dict()
    for i in range(1, n+1):
        adj[i] = []
    for _ in range(m):
        frm, to = IL()
        adj[frm].append(to)
        indegree[to]+=1
    
    result = []
    queue = []
    for key in adj:
        if indegree[key] == 0:
            heappush(queue, key)
    
    while queue:
        curr = heappop(queue)
        result.append(curr)
        for next in adj[curr]:
            indegree[next] -= 1
            if indegree[next] == 0:
                heappush(queue, next)
    
    if len(result) != n:
        print(-1)
    else:
        print(*result)

cases = 1
# cases = I()
for i in range(cases):
    solution()