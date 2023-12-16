class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        Top = 0
        Right = len(matrix[0]) - 1
        Bottom = len(matrix) - 1
        Left = 0

        stack = []

        while True:
            for i in range(Left, Right+1):
                stack.append(matrix[Top][i])
            if Bottom == Top:
                break
            Top += 1
            
            for i in range(Top, Bottom+1):
                stack.append(matrix[i][Right])
            if Right == Left:
                break
            Right -= 1
            
            for i in range(Right, Left-1, -1):
                stack.append(matrix[Bottom][i])
            if Top == Bottom:
                break
            Bottom -= 1
            
            for i in range(Bottom, Top-1, -1):
                stack.append(matrix[i][Left])
            if Right == Left:
                break
            Left += 1
        return stack