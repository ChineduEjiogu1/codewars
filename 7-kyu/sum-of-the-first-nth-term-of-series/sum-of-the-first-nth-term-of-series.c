#include <stdlib.h>
​
char *series_sum(size_t n)
{
// return a nul-terminated, heap-allocated string:
    int i = 1;
  
    char *buffer = (char *)malloc((51) * sizeof(char));
​
    float sum = 0;
  
    while (i <= n)
    {
        float terms = 1.0 / (3 * (i - 1) + 1);
        sum += terms;
        i++;
    }
  
    sprintf(buffer, "%.2f", sum);
  
    return buffer;
}