from functools import cmp_to_key

class Solution:
    def comparator(self, a: str, b: str) -> int:
        if (a+b) > (b+a):
            return -1
        elif (a+b) < (b+a):
            return 1
        else:
            return 0

    def largestNumber(self, nums: list[int]) -> str:
        stringifiedNums = list(map(str, nums))
        sortedSN = sorted(stringifiedNums, key=cmp_to_key(self.comparator))

        answer = str(int("".join(sortedSN)))
        return (answer)