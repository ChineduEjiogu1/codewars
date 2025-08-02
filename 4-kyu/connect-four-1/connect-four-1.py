def process_column(board, column_index, color_name, EMPTY):
    """
    Drops a piece into the specified column and returns the row where it lands.
    
    Args:
        board: 6x7 game board
        column_index: Column to drop piece (0-6)
        color_name: Color of piece ('Red' or 'Yellow')
        EMPTY: Value representing empty space (0)
    
    Returns:
        Row index where piece landed, or False if column is full
    """
    # Check from top to bottom (reversed range) to find lowest empty spot
    for row_index in reversed(range(6)):
        if board[row_index][column_index] == EMPTY:
            # Place the piece and return the row position
            board[row_index][column_index] = color_name
            return row_index
    # Column is full, can't place piece
    return False
​
def check_diagonal_1(board, row, col, color_name):
    """
    Checks for 4-in-a-row along the diagonal from top-left to bottom-right.
    
    Args:
        board: 6x7 game board
        row, col: Position of piece just placed
        color_name: Color to check for
    
    Returns:
        color_name if 4-in-a-row found, None otherwise
    """
    # Count pieces going up-left (↖️) and down-right (↘️)
    up_left_count = 0
    down_right_count = 0
    
    # Check up-left direction from the placed piece
    r, c = row - 1, col - 1
    while 0 <= r < 6 and 0 <= c < 7 and board[r][c] == color_name:
        up_left_count += 1
        r -= 1  # Move up
        c -= 1  # Move left
    
    # Check down-right direction from the placed piece
    r, c = row + 1, col + 1
    while 0 <= r < 6 and 0 <= c < 7 and board[r][c] == color_name:
        down_right_count += 1
        r += 1  # Move down
        c += 1  # Move right
    