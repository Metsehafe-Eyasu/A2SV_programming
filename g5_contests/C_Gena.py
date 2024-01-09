def intInput(): return int(input())
def intList(): return list(map(int, input().split()))
def strInput(): return input()


def solution():
    n = intInput()
    nums1 = intList()
    m = intInput()
    nums2 = intList()
    nums1.sort()
    nums2.sort()
    ptr1 = ptr2 = 0
    answer = 0
    while ptr1 < n and ptr2 < m:
        if abs(nums1[ptr1] - nums2[ptr2]) <= 1:
            answer += 1
            ptr1 += 1
            ptr2 += 1
        elif nums1[ptr1] < nums2[ptr2]:
            ptr1 += 1
        else:
            ptr2 += 1

    return answer




cases = 1
# cases = intInput()
for i in range(cases):
    print(solution())