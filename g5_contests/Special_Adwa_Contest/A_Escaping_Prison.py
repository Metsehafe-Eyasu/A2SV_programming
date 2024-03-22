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
    n, h = IL()
    blankets = 0
    for i in range(n):
        blankets += max(IL())
    return 'YES' if blankets >= h else 'NO'


cases = I()
# cases = 1
for i in range(cases):
    print(solution())