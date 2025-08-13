from collections import Counter
​
def anagram_counter(words):
    
    anagram_count = 0
​
    groups = {}
    
    for word in words:
        signature = tuple(sorted(Counter(word).items())) 
        groups[signature] = groups.get(signature, 0) + 1
    
    for count in groups.values(): 
        anagram_count += count * (count - 1) // 2
    
    return anagram_count