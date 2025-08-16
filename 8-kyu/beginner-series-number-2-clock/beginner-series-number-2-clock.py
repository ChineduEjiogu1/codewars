def past(h, m, s):
    # Good Luck!
    
    hours_milli = 3600000
    minutes_milli = 60000
    seconds_milli = 1000
    
    hours = 0
    minutes = 0
    seconds = 0
    
    if h > 0 and h <= 23:
        hours = h * hours_milli
    if m > 0 and m <= 59:
        minutes = m * minutes_milli
    if s > 0 and s <= 59:
        seconds = s * seconds_milli 
        
    result = hours + minutes + seconds
    
    return result