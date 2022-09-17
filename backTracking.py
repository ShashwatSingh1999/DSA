# N Queens problem
def isSafePos(board, curr_row, col):
    for k in range(curr_row):
        if (curr_row-k == abs(col-board[k])) or (board[k] == col):
            return False
    return True
# board[k] is position of a queen in kth row ie the queen sits at (k,board[k]) location in an sizexsize matrix


def nqueens(size):
    board = [-1]*size
    curr_row = 0
    while curr_row != -1:
        isPlaceFound = False
        for col in range(board[curr_row]+1, size):
            isPlaceFound = isSafePos(board, curr_row, col)
            if isPlaceFound:
                board[curr_row] = col
                curr_row += 1
                break
        if curr_row == size:
            print(board)
            board[-1] = -1
            curr_row = size-2
        if not isPlaceFound:
            board[curr_row] = -1
            curr_row -= 1


nqueens(4)
