#include <stdbool.h>
#include <string.h>
#include <ctype.h>
​
bool alphanumeric(const char *str_in) 
{
    //  <----  hajime!
    int str_in_length = strlen(str_in);
  
    if (str_in_length == 0) return false;
  
    for (int i = 0; i < str_in_length; i++) 
    {
        if (!(isalnum(str_in[i])))
        {
            return false;
        }
    }
  
    return true;
}