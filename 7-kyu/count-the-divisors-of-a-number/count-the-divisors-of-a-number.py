def divisors(n):
    
    k = 1
    divisors_counter = 0
    division = 0
    
    divisors = []
    
    while k <= n:
        division = n / k
        k += 1
        
        if n % k == 0 or n % k == n:
            divisors.append(k)
        
    return len(divisors)
        
        