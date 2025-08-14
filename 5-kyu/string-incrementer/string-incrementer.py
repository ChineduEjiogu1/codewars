def increment_string(strng):
    
    n = len(strng)
​
    for index, char in enumerate(reversed(strng)):
        
        original_index = n - 1 - index
        
        if not char.isdigit():
            split_index = original_index + 1
            number_part = strng[split_index:]
            
            if number_part == '':
                result = strng + "1"
                break
            else:
                incremented_number = int(number_part) + 1
                text_part = strng[:split_index]
                result = text_part + str(incremented_number).zfill(len(number_part))
                break
    else:
        split_index = 0
        number_part = strng[split_index:]
        
        if number_part == '':
            result = strng + "1"
        else:    
            text_part = ""
​
            incremented_number = int(number_part) + 1
            result = text_part + str(incremented_number).zfill(len(number_part))
​
    return result
​