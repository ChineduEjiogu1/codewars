def is_solved(board):
    
    # Check for horizontal wins
    for row in board:
        if all(cell == row[0] for cell in row) and row[0] != 0:
            return row[0]
        
    # Check for vertical wins
    for col in range(len(board[0])):
        if all(board[row][col] == board[0][col] for row in range(len(board))) and board[0][col] != 0:
            return board[0][col]
        
    # Check for diagonal wins
    if all(board[i][i] == board[0][0] for i in range(len(board))) and board[0][0] != 0:
        return board[0][0]
    
    if all(board[i][len(board) - 1 - i] == board[0][len(board) - 1] for i in range(len(board))) and board[0][len(board) - 1] != 0:
        return board[0][len(board) - 1]
​
    for row in board:
        if 0 in row:
            return -1
        
    return 0