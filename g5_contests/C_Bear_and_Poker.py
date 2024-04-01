from collections import defaultdict, deque, Counter
import heapq
import math
import itertools
import sys
import bisect

def I(): return int(input())
def IL(): return list(map(int, input().split()))
def S(): return input()

def factorize(n):
    while n > 1 and n%2 == 0:
        n//=2
    while n > 1 and n%3 == 0:
        n//=3
    return n

def solution():
    n = I()
    nums = IL()
    start = factorize(nums[0])
    for i in range(1, n):
        curr = factorize(nums[i])
        if curr != start:
            return 'No'
    return 'Yes'

cases = 1
# cases = I()
for i in range(cases):
    print(solution())