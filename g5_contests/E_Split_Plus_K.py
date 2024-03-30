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
    pos = neg = zero = 0
    total = 0
    for i in range(n):
        nums[i] -= k
        total += nums[i]
        if nums[i] > 0: pos = 1
        elif nums[i] == 0: zero = 1
        else: neg = 1
        
    if pos+neg+zero > 1:
        return -1
    if zero:
        return 0
    
    val = 0
    for num in nums:
        val = math.gcd(abs(num), val)    
    result = abs(total) // val - n
    return result

cases = 1
cases = I()
for i in range(cases):
    print(solution())