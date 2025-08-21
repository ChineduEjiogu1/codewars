#include <stdlib.h>
#include <string.h>
#include <ctype.h>
​
char *omit_non_alpha(const char *string)
{
    int j = 0;
    
    int length = strlen(string);
  
    char *result = (char *)malloc((length + 1) * sizeof(char)); 
  
    for (int i = 0; string[i] != '\0'; i++)
    {
        if ((isalpha((unsigned char)string[i])))
        {
            result[j++] = string[i];
        }
    }
            
    result[j] = '\0';
            
    return result;
}
                     
char *reverse_string(char *string) 
{     
    int left = 0;
    int right = strlen(string) - 1;
    char temp;
​
    while (left < right) 
    {
        temp = string[left];
        string[left] = string[right];
        string[right] = temp;
​
        left++;
        right--;
    }
  
    return string;
}
​
char *reverse_letter(const char *str)
{
// return a heap-allocated string:
  
    char *alpha_only = omit_non_alpha(str);
  
    reverse_string(alpha_only);
  
    return alpha_only;
}