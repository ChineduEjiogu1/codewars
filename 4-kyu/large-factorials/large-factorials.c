#include <stdlib.h>
​
char *factorial(int n) 
{
    // TODO: Compute the exact value of n! and return the result
    // as a heap-allocated string
  
    if (n < 0) 
    {                          // negative → empty string sentinel
        char *empty = malloc(1);
      
        if (empty) empty[0] = '\0';
        return empty;
    }
​
    int digits[40000];                    // units-first digit array
    digits[0] = 1;                        // starts as 1 (also handles 0! and 1!)
    int length = 1;
    
    for (int multiplier = 2; multiplier <= n; multiplier++) 
    {
      
        int carry = 0;
​
        // multiply every existing digit by multiplier, propagating carry
        for (int i = 0; i < length; i++) 
        {
            int product = digits[i] * multiplier + carry;
            digits[i] = product % 10;   // digit that stays
            carry = product / 10;   // overflow into the next column
        }
​
        // drain whatever carry is left into new high-order digits
        while (carry > 0) 
        {
            digits[length] = carry % 10;
            carry /= 10;
            length++;
        }
    }
  
    char *result = malloc(length + 1); // reversed digits → forward string
  
    if (!result) return NULL;
  
    for (int i = 0; i < length; i++)
        result[i] = digits[length - 1 - i] + '0';
  
    result[length] = '\0';
    return result;
}