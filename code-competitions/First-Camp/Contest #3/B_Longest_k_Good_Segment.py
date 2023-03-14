from collections import defaultdict

def intInput(): return int(input())
def intList(): return list(map(int, input().split()))
def strInput(): return input()


def solution():
    length, param = intList()
    array = intList()
    window = defaultdict(int)
    left = 0
    count = 0
    ans = 0
    lMost = rMost = 0
    for right in range(length):
        if window[array[right]] == 0:
            count += 1
        window[array[right]] += 1
        
        while left < right and count > param:
            window[array[left]] -= 1
            if window[array[left]] == 0:
                count -= 1
            left += 1
        
        if right - left + 1 > ans:
            lMost = left
            rMost = right
            ans = right - left + 1
            
    
    return (lMost + 1, rMost + 1)




# cases = intInput()
cases = 1
for i in range(cases):
    print(*solution())