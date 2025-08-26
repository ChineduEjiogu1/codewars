def grow(arr):
    
    sum = 1
    
    for i in range(len(arr)):
        sum *= arr[i]
    
    return sum