def reverse_list(l):
    'return a list with the reverse order of l'
    result = []
    
    for item in reversed(l):
        result.append(item)
    
    return result