class TopVotedCandidate:

    def __init__(self, persons: List[int], times: List[int]):
        count = defaultdict(int)
        self.topCandidate = []
        self.times = times
        leader = -1

        for person in persons:
            count[person] += 1
            if count[person] >= count[leader]: leader = person
            self.topCandidate.append(leader)

    def q(self, t: int) -> int:
        left, right = 0, len(self.times)
        while left < right:
            mid = left + (right - left) // 2
            if self.times[mid] > t:
                right = mid
            else:
                left = mid + 1
        return self.topCandidate[left - 1]


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)