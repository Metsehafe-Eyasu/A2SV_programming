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
    while n > 1 and n%2 == 0:
        n//=2
    return 'YES' if n > 1 else 'NO'

cases = 1
cases = I()
for i in range(cases):
    print(solution())