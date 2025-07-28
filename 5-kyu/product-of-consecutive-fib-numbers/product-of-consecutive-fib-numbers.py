def product_fib(_prod):
    
    a, b = 0, 1
            
    while True:
        current_product = a * b
        if current_product == _prod:
            return [a, b, True]
        elif current_product > _prod:
            return [a, b, False]
        a, b = b, a + b