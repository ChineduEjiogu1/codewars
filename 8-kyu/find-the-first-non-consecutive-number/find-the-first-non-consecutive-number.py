def first_non_consecutive(arr):
    
    if len(arr) <= 1:
        return None
​
    for i in range(len(arr) - 1):
        if arr[i + 1] != arr[i] + 1:
            return arr[i + 1]
    return None