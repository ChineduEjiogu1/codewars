def expanded_form(num):
    
    number_str = str(num)
    num_digits = len(number_str)
    components = []
    
    decimal_index = number_str.find('.')  # Find where decimal is
    
    for i, digit_char in enumerate(number_str):
        
        if digit_char == '.':
            continue
        if i > decimal_index:  # After decimal
            digit = int(digit_char)
            decimal_position = i - decimal_index
            denominator = 10**decimal_position
            if digit > 0:  # for fractional
                components.append(f"{digit}/{denominator}")
        else:
            if decimal_index == -1:  # No decimal point
                whole_digits = num_digits
            else:
                whole_digits = decimal_index
            digit = int(digit_char)
            place_value = 10**(whole_digits - 1 - i)
            multiplied_value = digit * place_value
            if multiplied_value > 0:
                components.append(str(multiplied_value))
        
    return ' + '.join(components)