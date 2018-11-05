"""
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
"""

def isValidSudoku(self, board):
    """
    :type board: List[List[str]]
    :rtype: bool
    """
    for i in range(len(board)):
        _hash = [0]*9
        for j in range(len(board[0])):
            if board[i][j] == ".":
                continue
            else:
                x = int(board[i][j])
                _hash[x-1] += 1
            if _hash[x-1] > 1:
                return False
    
    #check columnwise
    for j in range(len(board[0])):
        _hash = [0]*9
        for i in range(len(board)):
            if board[i][j] == ".":
                continue
            else:
                x = int(board[i][j])
                _hash[x-1] += 1
            if _hash[x-1] > 1:
                return False

    #check square wise
    for i in range(0,len(board),3):
        for j in range(0,len(board[0]),3):
            row_start = i
            col_start = j
            _hash = [0]*(9)
            while(row_start < i + 3):
                while(col_start < j + 3):
                    if board[row_start][col_start] != ".":
                        x = int(board[row_start][col_start])
                        _hash[x -1] += 1
                        if _hash[x-1] > 1:
                            return False
                    col_start += 1
                col_start=j
                row_start += 1
    return True
