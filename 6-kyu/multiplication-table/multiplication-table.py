def multiplication_table(size):
    matrix = [[(i + 1) * (j + 1) for j in range(size)] for i in range(size)]
    return matrix