{
    if (string == NULL) return NULL;
​
    size_t len = strlen(string);
​
    // Allocate memory for the new encoded string (+1 for null terminator)
    char *result = malloc(len + 1);
  
    if (result == NULL) 
    {
        return NULL; // Allocation failed
    }
  
    for (size_t i = 0; i < len; i++) 
    {
        char ch = string[i];
​
        // 1. If not an alphabetic character, keep original and move on
        if (!isalpha((unsigned char)ch)) 
        {
            result[i] = ch;
            continue;
        }
​
        char vowel_digit = get_vowel_digit(ch);
​
        // 2. If not a vowel, keep original and move on
        if (vowel_digit == '\0') 
        {
            result[i] = ch;
            continue;
        }
​
        // 3. It's an alphabetic vowel -> replace with digit '1'-'5'
        result[i] = vowel_digit;
    }
​
    result[len] = '\0'; // Set null terminator
    return result;
}
​
char *decode(const char *string) 
{
    if (string == NULL) return NULL;
​
    size_t len = strlen(string);
    char *result = malloc(len + 1);
  
    if (result == NULL) return NULL;
​
    for (size_t i = 0; i < len; i++) 
    {
        char ch = string[i];
​
        // If the character is a digit '1'-'5', convert back to its vowel
        char vowel = digit_to_vowel(ch);
      
        if (vowel != '\0') 
        {
            result[i] = vowel;
          
        } 
        else 
        {
            result[i] = ch; // Keep all other characters as-is
        }
    }
​
    result[len] = '\0';
    return result;
}