def sum_pairs(ints, s):
​
    
    my_hash_map = {}
    
    for i, j in enumerate(ints):
        complement = s - j
        if complement in my_hash_map:
                current_index_sum = i
                return [ints[my_hash_map[complement]], j]
        my_hash_map[j] = i