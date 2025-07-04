def to_postfix (infix):
    """Convert infix to postfix"""
    
    output_list = []
    operator_stack = []
​
    precedence_dict = {
        "^": 4,
        "*": 3, 
        "/": 3,    
        "+": 2,
        "-": 2
    }
    
    for char in infix:
​
        if char.isdigit():
            # Action: add to output
            output_list.append(char)
        elif char == '(':
            # Action: push to stack 
            operator_stack.append(char)
        elif char == ')':
            # Action: pop until matching (
            while operator_stack and operator_stack[-1] != '(':
                output_list.append(operator_stack.pop())
            operator_stack.pop()
​
        elif char in precedence_dict:
            
            current_precedence = precedence_dict[char]
​
            if char == '^':  # right-associative
                while (operator_stack and 
                       operator_stack[-1] != '(' and 
                       precedence_dict[operator_stack[-1]] > current_precedence):
                    output_list.append(operator_stack.pop())
            else:  # left-associative
                while (operator_stack and 
                       operator_stack[-1] != '(' and 
                       precedence_dict[operator_stack[-1]] >= current_precedence):
                    output_list.append(operator_stack.pop())
​
            operator_stack.append(char)
            
    while operator_stack:
        output_list.append(operator_stack.pop())
    return ''.join(output_list)
                