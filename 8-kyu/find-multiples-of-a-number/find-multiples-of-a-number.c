#include <stddef.h>
​
typedef unsigned int uint;
​
void find_multiples(uint n, uint limit, size_t *count, uint multiples[])
{
    // fill `multiples`
    // report the length through `count`
  
    int j = 0;
    
    for (int i = 1; i*n <= limit; i++)
    {
        multiples[j++] = i * n;
    }
  
     *count = j;
}