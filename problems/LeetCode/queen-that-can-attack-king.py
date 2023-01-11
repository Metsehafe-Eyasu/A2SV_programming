class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        answer = []
        queenSet = set(map(tuple, queens))
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0], [1, 1], [-1, 1],[1, -1], [-1, -1]]

        for directionX, directionY in directions:
            currentX = king[0]
            currentY = king[1]
            while currentX < 8 and currentY < 8 and currentX >=0 and currentY >= 0:
                if (currentX, currentY) in queenSet:
                    answer.append([currentX, currentY])
                    break
                currentX += directionX
                currentY += directionY
        return answer