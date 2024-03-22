from collections import defaultdict, deque
import heapq
import math
import itertools
import sys
import bisect

def I(): return int(input())
def IL(): return list(map(int, input().split()))
def S(): return input()

def merge(left, right):
    l = r = 0
    result = []
    copyleft = [[val, key] for val, key in left]
    for i in range(len(left)):
        left[i][0] += bisect.bisect_left(right, [left[i][0], 0])
    for i in range(len(right)):
        right[i][0] += bisect.bisect_left(copyleft, [right[i][0], 0])
        
    while l < len(left) and r < len(right):
        if left[l][0] <= right[r][0]:
            result.append(left[l])
            l+=1
        else:
            result.append(right[r])
            r+=1
            
    result.extend(left[l:])
    result.extend(right[r:])
    return result

def mergesort(l, r, nums):
    if l == r:
        return [[nums[l], l]]
    mid = (l+r)//2
    left = mergesort(l, mid, nums)
    right = mergesort(mid+1, r, nums)
    return merge(left, right)

def solution():
    n = I()
    nums = IL()
    x = mergesort(0, 2**n - 1, nums)
    ans = [0]*(2**n)
    for val, idx in x:
        ans[idx] = val
    return ans



cases = I()
# cases = 1
for i in range(cases):
    print(*solution())