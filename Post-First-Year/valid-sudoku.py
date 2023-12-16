class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        subGrids= [set() for _ in range(9)]

        for i in range(9):
            for j in range(9):
                if board[i][j] != '.' and board[i][j] not in cols[j] and board[i][j] not in rows[i]:
                    cols[j].add(board[i][j])
                    rows[i].add(board[i][j])
                elif board[i][j] in cols[j] or board[i][j] in rows[i]:
                    return False
                if board[i][j] != '.':
                    if i in set([0, 1, 2]):
                        if j in set([0, 1, 2]) and board[i][j] not in subGrids[0]:
                            subGrids[0].add(board[i][j])
                        elif j in set([3, 4, 5]) and board[i][j] not in subGrids[1]:
                            subGrids[1].add(board[i][j])
                        elif j in set([6, 7, 8]) and board[i][j] not in subGrids[2]:
                            subGrids[2].add(board[i][j])
                        elif board[i][j] in subGrids[0] or board[i][j] in subGrids[1] or board[i][j] in subGrids[2]:
                            return False 
                    elif i in set([3, 4, 5]):
                        if j in set([0, 1, 2]) and board[i][j] not in subGrids[3]:
                            subGrids[3].add(board[i][j])
                        elif j in set([3, 4, 5]) and board[i][j] not in subGrids[4]:
                            subGrids[4].add(board[i][j])
                        elif j in set([6, 7, 8]) and board[i][j] not in subGrids[5]:
                            subGrids[5].add(board[i][j])
                        elif board[i][j] in subGrids[3] or board[i][j] in subGrids[4] or board[i][j] in subGrids[5]:
                            return False 
                    elif i in set([6, 7, 8]):
                        if j in set([0, 1, 2]) and board[i][j] not in subGrids[6]:
                            subGrids[6].add(board[i][j])
                        elif j in set([3, 4, 5]) and board[i][j] not in subGrids[7]:
                            subGrids[7].add(board[i][j])
                        elif j in set([6, 7, 8]) and board[i][j] not in subGrids[8]:
                            subGrids[8].add(board[i][j])
                        elif board[i][j] in subGrids[6] or board[i][j] in subGrids[7] or board[i][j] in subGrids[8]:
                            return False 
        return True