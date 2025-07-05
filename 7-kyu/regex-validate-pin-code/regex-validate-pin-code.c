#include <stdbool.h>
#include <stdlib.h>
#include <regex.h>
​
bool validate_pin(const char *pin) 
{
    //  <----  hajime!
    regex_t regex_pattern;
​
    int value = regcomp(&regex_pattern, "^([[:digit:]]{4}|[[:digit:]]{6})$", REG_EXTENDED);
  
    if (value != 0)  
    {
        return false;
    }
  
    else
    {
        value = regexec(&regex_pattern, pin, 0, NULL, 0);
    }
  
    regfree(&regex_pattern);
    
    return(!value);
}