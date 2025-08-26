def powers_of_two(n):
    
    powers = []
    k = 0
    
    while k <= n:
        result = 2 ** k
        powers.append(result)
        k += 1
    
    return powers