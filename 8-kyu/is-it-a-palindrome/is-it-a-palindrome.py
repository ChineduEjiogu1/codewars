def is_palindrome(s):
    
    s = s.lower()
    n = len(s)
    half = n // 2
    
    if n % 2 == 0:
        first_half = s[:half]
        second_half = s[half:]
    else:
        first_half = s[:half]
        second_half = s[half+1:]
        
    return first_half == second_half[::-1]
​
    