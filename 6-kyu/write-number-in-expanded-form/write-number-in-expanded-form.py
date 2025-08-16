def expanded_form(num):
    
    number_str = str(num)
    num_digits = len(number_str)
    result = ""
    
    for i, digit_char in enumerate(number_str):
        digit = int(digit_char)
        place_value = 10**(num_digits - 1 - i)
        multiplied_value = digit * place_value
        if multiplied_value > 0:
            result += str(multiplied_value) + ' + '
        
    return result.rstrip(' + ')
        
        