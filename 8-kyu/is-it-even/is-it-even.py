import math
​
def is_even(n): 
    # your code here
    if math.fmod(n, 2) == 0:
        return True
    else:
        return False