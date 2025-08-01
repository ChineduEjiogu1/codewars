def solution(s):
    
    pairs = []
    
    if len(s) % 2 != 0:
        s += '_'
    
    for i in range(0, len(s), 2):
        pairs.append(s[i:i + 2])
        
    return pairs