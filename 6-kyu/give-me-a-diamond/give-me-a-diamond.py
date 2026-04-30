def diamond(n):
    # Make some diamonds!
    
    if n % 2 == 0 or n < 0:
        return None
    i = 0
    
    star_counter = 1
    
    up = True
    down = False
    
    result = ""
    
    while i < n: 
           
        if star_counter < n and up:
            result += ('*' * star_counter).center(n).rstrip() + '\n'
            star_counter += 2
        elif star_counter == n and up:
            up = False
            down = True
            result += ('*' * star_counter).center(n).rstrip() + '\n'
            star_counter -= 2
            
        elif down:
            result += ('*' * star_counter).center(n).rstrip() + '\n'
            star_counter -= 2
            
        i += 1   
        
    return result