#include <stddef.h>
​
//  don't allocate memory for a return value
//  assign integers to pre-allocated result[]
//  set the size of result array to *res_len
​
void bin_mul(unsigned m, unsigned n, unsigned result[], size_t *res_len) 
{
​
    //  <----  hajime!
    if (n == 0 || m == 0) { *res_len = 0; return; }
​
    unsigned halve  = (m >= n) ? m : n;    // the larger gets halved
    unsigned record = (m >= n) ? n : m;    // the smaller gets doubled & recorded
​
    size_t count = 0;
  
    for (; halve > 0; halve /= 2) 
    {
        if (halve % 2 != 0)
            result[count++] = record;
        record *= 2;
    }
  
    *res_len = count;
​
    for (size_t i = 0; i < count / 2; i++) 
    {
        unsigned temp = result[i];
        result[i] = result[count - 1 - i];
        result[count - 1 - i] = temp;
    }
}