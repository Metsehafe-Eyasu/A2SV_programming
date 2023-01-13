class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        row = len(mat)
        col = len(mat[0])
        currTotal = row*col
        newTotal = r*c
        if currTotal != newTotal:
            return mat


        flag = 0
        newMat = [[] for _ in range(r)]
        for oldRow in mat:
            for item in oldRow:
                newMat[flag].append(item)
                if len(newMat[flag]) == c:
                    flag += 1
        return newMat