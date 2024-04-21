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
    n, k, q = IL()
    friends = IL()
    seen = [False] * n
    heap = []
    for _ in range(q):
        t, i = IL()
        i -= 1
        if t == 1:
            heappush(heap, (friends[i], i))
            seen[i] = True
            if len(heap) > k:
                val, key = heappop(heap)
                seen[key] = False
        else:
            print('YES' if seen[i] else 'NO')
        

cases = 1
# cases = I()
for i in range(cases):
    solution()