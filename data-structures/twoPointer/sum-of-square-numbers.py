class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        squares = []
        for i in range(c+1):
            if i**2 <= c:
                squares.append(i**2)
            else:
                break
        
        right = len(squares)-1
        left = 0

        while left <= right:
            if squares[left] + squares[right] == c:
                return True
            elif squares[left] + squares[right] > c:
                right -= 1
            else:
                left += 1

        return False