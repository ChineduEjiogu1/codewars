def josephus(items,k):
    #your code here
    
    result = []
    current_array = list(items)
    current_position = 0
    
    for i in range(0, len(items)):
        index_to_remove = (current_position + k - 1) % len(current_array)
        before_removal = len(current_array)
        removed_element = current_array.pop(index_to_remove)
        result.append(removed_element)
        
        if index_to_remove == before_removal - 1:
            current_position = 0
        else:
            current_position = index_to_remove
            
    return result