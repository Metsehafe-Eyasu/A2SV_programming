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
    n ,k = IL()
    s = ''
    for i in range(n):
        ch = chr(ord('a') + (i%k))
        s += ch
    return s

cases = 1
cases = I()
for i in range(cases):
    print(solution())