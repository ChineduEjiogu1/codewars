def count(s):
    # The function code should be here
    
    char_counts = {}
    for char in s:
        char_counts[char] = char_counts.get(char, 0) + 1
            
    return char_counts