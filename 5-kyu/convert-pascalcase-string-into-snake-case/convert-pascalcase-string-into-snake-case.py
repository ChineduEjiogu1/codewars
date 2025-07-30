import re
​
def to_underscore(strng: str) -> str:
      # your code here
        
    if isinstance(strng, (int, float)):
        s = str(strng)
        return s
    
    elif isinstance(strng, str):
         return re.sub(r'(?<!^)(?=[A-Z])', '_', strng).lower()