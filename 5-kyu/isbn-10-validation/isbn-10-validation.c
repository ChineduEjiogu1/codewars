#include <stdbool.h>
#include <string.h>
​
bool is_valid_ISBN_10 (const char *ISBN)
{
    int position = 1;
    
    int converted_to_integer;
  
    int isbn_length = strlen(ISBN);
  
    int sum = 0;
  
    if (isbn_length != 10)
    {
        return false;
    }
  
    for (int i = 0; i < isbn_length; i++)
    {
        if (ISBN[i] == 'X' && i == isbn_length - 1)
        {
            continue;
        }
        else if (ISBN[i] >= '0' && ISBN[i]  <= '9')
        {
            continue;
        }
        else
        {
            return false;
        }  
    }
  
    for (int i = 0; i < isbn_length; i++)
    {
        if (ISBN[i] == 'X' && i == isbn_length - 1)
        {
            converted_to_integer = 10;
        }
        else
        {
            converted_to_integer = ISBN[i] - '0';
        }
      
        int isbn_conversion = converted_to_integer * position;
        
        sum += isbn_conversion;
      
        position++;
    }
  
    if (sum % 11 == 0)
    {
        return true;
    }
  
    return false;
}