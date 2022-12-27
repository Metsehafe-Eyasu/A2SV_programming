class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        mappedNums = {
            '0': 0,
            '1': 1,
            '2': 2,
            '3': 3,
            '4': 4,
            '5': 5,
            '6': 6,
            '7': 7,
            '8': 8,
            '9': 9
        }
        ans1 = 0
        ans2 = 0

        for i in num1:
            ans1 = 10*ans1 + mappedNums[i]
        for i in num2:
            ans2 = 10*ans2 + mappedNums[i]

        return str(ans1*ans2)