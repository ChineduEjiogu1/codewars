def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)
​
def lcm(a, b):
    return (a * b) // gcd(a, b)
    
def convert_fracts(lst):
    
    if not lst:  
        return []
    
    denominators = []
    for my_tuple in lst:
        denominators.append(my_tuple[1])
    
    result = denominators[0]
    for i in range(1, len(denominators)):
        result = lcm(result, denominators[i])
    
    tuple_list = []
    for my_tuple in lst:
        num = my_tuple[0]         
        denom = my_tuple[1]       
        multiplier = result // denom
        tuple_list.append([num * multiplier, result])
    
    return tuple_list