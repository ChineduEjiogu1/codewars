def is_valid(puzzle, row, col, num):
    
    for row_idx in range(9):
        if puzzle[row][row_idx] == num:
            return False
​
    for col_idx in range(9):
        if puzzle[col_idx][col] == num:
                return False
​
    box_start_row = row - row % 3
    box_start_col = col - col % 3
        
    for i in range(3):
        for j in range(3):
            if puzzle[i + box_start_row][j +  box_start_col] == num:
                return False
    return True
​
def find_best_cell(puzzle):
    
    best = None
    min_options = 10
​
    for row in range(9):
        for col in range(9):
            if puzzle[row][col] == 0:
                count = 0
                for num in range(1, 10):
                    if is_valid(puzzle, row, col, num):
                        count += 1
                if count < min_options:
                    min_options = count
                    best = (row, col)
                if min_options == 1:
                    return best
    return best
​
def solve_sudoku(puzzle):
    
    empty_cell = find_best_cell(puzzle)
    if empty_cell is None:
        return True
​
    row, col = empty_cell
    
    for num in range(1, 10):
        if is_valid(puzzle, row, col, num):
            puzzle[row][col] = num
            if solve_sudoku(puzzle):
                return True
            puzzle[row][col] = 0
    return False
​
def solve(board):
    solve_sudoku(board)    
    return board