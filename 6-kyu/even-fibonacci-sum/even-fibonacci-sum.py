def even_fib(n):
    
    a, b = 0, 1
    sum = 0
    
    current_fib = a
    
    while current_fib < n:
        if current_fib % 2 == 0:
            sum += current_fib   
        a, b = b, a+b   
        current_fib = a
    
    return sum