from collections import Counter
​
def find_missing(sequence):
    
    if len(sequence) < 3:
        return None
    
    common_difference_frequency = [sequence[i + 1] - sequence[i] for i in range(len(sequence) - 1)]
    common_difference_counts = Counter(common_difference_frequency)
    common_difference = common_difference_counts.most_common(1)[0][0]
​
    for i in range(len(sequence) - 1):
        if sequence[i + 1] - sequence[i] == 2 * common_difference:
            missing_number = sequence[i] + common_difference
            return missing_number
    return None