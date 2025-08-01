def sq_in_rect(lng, wdth):
    # your code
    
    sq_in_rec_list = []
    
    if lng== wdth: return None
    
    smaller_dimension = min(lng, wdth)
    larger_dimension = max(lng, wdth)
    
    new_larger_dimension = larger_dimension - smaller_dimension
    new_smaller_dimension = smaller_dimension
    
    if new_larger_dimension == new_smaller_dimension:
        return [smaller_dimension, new_smaller_dimension]
    
    calculated_values = sq_in_rect(new_larger_dimension, new_smaller_dimension)
    
    sq_in_rec_list.append(smaller_dimension)
    sq_in_rec_list.extend(calculated_values)
    
    return sq_in_rec_list