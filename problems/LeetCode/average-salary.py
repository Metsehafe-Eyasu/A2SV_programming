class Solution:
    def average(self, salary: List[int]) -> float:
        salary.sort()
        salary.pop(0)
        salary.pop()
        average = 0
        for i in salary:
            average += i
        total = len(salary)
        average /= total
        return average