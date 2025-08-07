#include <stddef.h>
​
int find_smallest_int(const int array[/* len */], size_t len)
{
    int min = array[0];
      
    for (int i = 0; i < len; i++)
    {
        if (array[i] < min) 
        {
            min = array[i];
        }
    }
  
    return min;
}