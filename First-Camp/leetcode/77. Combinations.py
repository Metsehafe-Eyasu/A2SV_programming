class Solution:
    def backtrack(self, index, path):
        if len(path) == self.length:
            self.combinations.append(path[:])
            return
        
        if index >= self.total:
            return

        path.append(self.nums[index])
        self.backtrack(index + 1, path)
        path.pop()

        self.backtrack(index + 1, path)

    def combine(self, n: int, k: int) -> List[List[int]]:
        self.nums = [i for i in range(1, n + 1)]
        self.length = k
        self.total = n
        self.combinations = []
        self.backtrack(0, [])
        return self.combinations