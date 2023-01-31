class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        boats = 0
        left = 0
        right = len(people)-1

        while left <= right:
            if people[right] + people[left] <= limit:
                boats += 1
                left += 1
                right -= 1
            elif people[right] <= limit:
                boats += 1
                right -= 1

        return boats 