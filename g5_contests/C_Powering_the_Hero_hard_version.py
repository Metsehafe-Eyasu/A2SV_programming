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
    n = I()
    nums = IL()
    heap = []
    result = 0
    for num in nums:
        if num == 0:
            if heap:
                result -= heappop(heap)
        else:
            heappush(heap, -num)
            
    return result

cases = 1
cases = I()
for i in range(cases):
    print(solution())