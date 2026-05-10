from collections import Counter
​
def permute_a_palindrome(input): 
    return sum(1 for i in Counter(input).values() if i % 2 != 0) <= 1