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
    nums = IL()
    total = min_ = max_ = 0
    for num in nums:
        total += num
        max_ = max(total - min_, max_)
        min_ = min(min_, total)
    total += max_*(2**k - 1)
    return total%(1000000007)

cases = 1
cases = I()
for i in range(cases):
    print(solution())