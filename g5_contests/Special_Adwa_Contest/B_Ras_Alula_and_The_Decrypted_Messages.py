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
    n, m = IL()
    decryped = S()
    sensitive = S()
    window = 0
    sensitive_sum = sum([ord(ch) for ch in sensitive])
    for i in range(m):
        window += ord(decryped[i])
    if window == sensitive_sum:
        return 'Yes'
    
    for i in range(m, n):
        window += ord(decryped[i]) - ord(decryped[i-m])
        if window == sensitive_sum:
            return 'Yes'
    return 'No'


cases = I()
# cases = 1
for i in range(cases):
    print(solution())