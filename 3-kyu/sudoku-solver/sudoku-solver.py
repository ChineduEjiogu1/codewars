def find_empty_cell(puzzle):
    for row in range(9):
        for col in range(9):
            if puzzle[row][col] == 0:
                return (row, col)
    return None

def solve_sudoku(puzzle):
    
    empty_cell = find_empty_cell(puzzle)
    if empty_cell is None:
        return True
    
    row, col = empty_cell
    
    numbers_already_used = set()
    all_possible_numbers = set(range(1, 10))

    for col_idx in range(0, 9):
        if puzzle[row][col_idx] != 0:
            numbers_already_used.add(puzzle[row][col_idx])

    for row_idx in range(9):
        if puzzle[row_idx][col] != 0:
            numbers_already_used.add(puzzle[row_idx][col])
            
    box_start_row = (row // 3) * 3
    box_start_col = (col // 3) * 3
    
    for i in range(box_start_row, box_start_row + 3):
        for j in range(box_start_col, box_start_col + 3):
            if puzzle[i][j] != 0:
                numbers_already_used.add(puzzle[i][j])
                
    available_numbers = list(all_possible_numbers - numbers_already_used)
    
    for num in available_numbers:
        puzzle[row][col] = num        
        if solve_sudoku(puzzle):      
            return True               
        puzzle[row][col] = 0          
    return False                     
    
def sudoku(puzzle):
    """return the solved puzzle as a 2d array of 9 x 9"""
    solve_sudoku(puzzle)    
    return puzzle
