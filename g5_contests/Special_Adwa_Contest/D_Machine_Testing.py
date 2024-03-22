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
    n = I()
    health = IL()
    power = IL()
    stack = [(power[0], sum(health))]
    max_time = 0
    for i in range(1, n):
        time = 0
        rem_health = health[i]
        while stack and rem_health > 0:
            att_power, dur = stack.pop()
            if rem_health <= att_power*dur:
                new_dur = math.ceil(rem_health/att_power)
                rem_health -= att_power*new_dur
                if new_dur < dur:
                    stack.append((att_power, dur - new_dur))
                time += new_dur
            else:
                rem_health -= att_power*dur
                time += dur
        
        stack.append((power[i], time))
        max_time = max(max_time, time)
        
        
    return max_time



cases = I()
# cases = 1
for i in range(cases):
    print(solution())