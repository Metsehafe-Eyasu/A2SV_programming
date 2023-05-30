from collections import defaultdict

class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root_x, root_y = self.find(x), self.find(y)
        if root_x == root_y:
            return

        if self.rank[root_x] > self.rank[root_y]:
            root_x, root_y = root_y, root_x

        self.parent[root_x] = root_y
        if self.rank[root_x] == self.rank[root_y]:
            self.rank[root_y] += 1

    def is_identical(self, x, y):
        return self.find(x) == self.find(y)


def is_possible(a, b):
    n, m = len(a), len(b)
    uf = UnionFind(n)

    replaced_a = ''
    replaced_b = ''

    for i in range(n):
        while i < m and a[i] == '-':
            i += 1
        replaced_a += a[i]

    for i in range(n):
        while i < m and b[i] == '-':
            i += 1
        replaced_b += b[i]

    num_replacements = 0
    for i in range(n):
        if a[i] != b[i]:
            num_replacements += 1
            uf.union(i, i)
            replaced_a = replaced_b[i] + a[i] + replaced_b[i+1:]
            replaced_b = replaced_a[i:] + replaced_b[i]

    return num_replacements == n or num_replacements == m

a = input()
b = input()

print(is_possible(a, b))
