def generate_hashtag(s):
    #your code here
    
    if s == "":
        return False
    
    cleaned_text = " ".join(s.strip().split())
    
    title_string = cleaned_text.title()
​
    final_string = "#" + title_string.replace(" ", "")
    
    if len(final_string) > 140:
        return False
    
    return final_string