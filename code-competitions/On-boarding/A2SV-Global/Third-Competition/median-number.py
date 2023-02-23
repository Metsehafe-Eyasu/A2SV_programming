cases = int(input())
for _ in range(cases):
    nums = list(map(int, input().split()))
    nums.sort()
    print(nums[1])
    