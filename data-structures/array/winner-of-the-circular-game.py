class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        players = [i for i in range(1, n + 1)]
        current = -1

        for i in range(n-1):
            increment = 0
            while increment < k:
                current = (current + 1)%n
                while players[current] == 0:
                    current = (current + 1)%n
                increment += 1
            players[current] = 0
                
        for i in players:
            if i != 0:
                return i