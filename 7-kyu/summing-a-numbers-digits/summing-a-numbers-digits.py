def sum_digits(number):
    
    num_str = str(number)
    sum = 0
    
    for digit in num_str:
        if digit.isdigit():
            sum += abs(int(digit))
    
    return sum