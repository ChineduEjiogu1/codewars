def to_alternating_case(string):
    
    mutable_list = list(string)
    
    for i in range(len(mutable_list)):
        if mutable_list[i].isupper():
            mutable_list[i] = mutable_list[i].lower()
        elif mutable_list[i].lower():
            mutable_list[i] = mutable_list[i].upper()
            
    mutated_string = "".join(mutable_list)
            
    return mutated_string
​