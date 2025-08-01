def find_missing_letter(chars):
    
    for i in range(len(chars) - 1): # Iterate through the array up to the second-to-last element
        if ord(chars[i + 1]) - ord(chars[i]) > 1: # Calculate the difference in ASCII values between consecutive characters
            return chr(ord(chars[i]) + 1) # If the difference is greater than 1, the missing letter is the next character after the current one, converted from its ASCII value to a character and returned in an array
    
    
​
​