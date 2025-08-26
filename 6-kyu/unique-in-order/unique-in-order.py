def unique_in_order(sequence):
    
    result = []
    
    if sequence:  # Handle empty case
        result.append(sequence[0])  # Always add first
        
    for i in range(1, len(sequence)):
        if sequence[i] != sequence[i-1]:  # Different from previous
            result.append(sequence[i])
    
    return result