class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        pointsLength = len(points)
        smallIndex = 0
        smallestVal = float('inf')
        checkValid = True
        checker = False
        for i in range(pointsLength):

            if x == points[i][0] or y == points[i][1]:
                checkValid = True
                checker = True
            else:
                checkValid = False
                
            if checkValid:
                manDistance = abs(x - points[i][0]) + abs(y - points[i][1])
                if manDistance < smallestVal:
                    smallestVal = manDistance
                    smallIndex = i

        if not checker:
            return -1
        return smallIndex
