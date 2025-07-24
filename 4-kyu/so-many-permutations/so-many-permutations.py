from itertools import permutations as perm
from collections import OrderedDict
​
def permutations(s):
    # Code Away!
    
    all_permutations = [''.join(p) for p in perm(s)]
    unique_permutations = list(OrderedDict.fromkeys(all_permutations))
    return unique_permutations