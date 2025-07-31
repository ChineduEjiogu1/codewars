from collections import Counter
​
def highest_rank(arr):
    
    arr_counts = Counter(arr)
​
    max_frequency = 0
    if arr_counts:
        max_frequency = max(arr_counts.values())
​
    most_frequent = [num for num, freq in arr_counts.items() if freq == max_frequency]
​
    return max(most_frequent)
​