def parts_sums(ls):
    # your code
    
    total = sum(ls)
    result = [total]
    
    current_sum = total
    
    for item in ls:
        current_sum -= item
        
        result.append(current_sum)
​
    return result
        