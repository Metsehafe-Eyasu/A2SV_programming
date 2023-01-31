class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort()
        length = len(skill)

        sumTotal = 0

        left = 0
        right = length - 1
        initial = skill[left] + skill[right]

        while left < right:
            if skill[right] + skill[left] == initial:
                sumTotal += skill[right]*skill[left]
                left += 1
                right -= 1
            else:
                return -1
        return sumTotal