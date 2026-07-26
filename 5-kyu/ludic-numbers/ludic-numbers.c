#include <stdlib.h>
​
static long long prefix[10001];   // prefix[i] = sum of the first i ludic numbers
static int ready = 0;
​
static void build(void)
{
    const int cap = 140000;       // 10000th ludic ≈ 128613, safely under
    int *arr = malloc((size_t)cap * sizeof(int));
    int len = 0;
  
    for (int v = 2; v < cap; v++) arr[len++] = v;
​
    int count = 1;
    prefix[1] = 1; // first ludic is 1
  
    while (count < 10000 && len > 0) 
    {
        int k = arr[0];
        count++;
        prefix[count] = prefix[count - 1] + k;
      
        int w = 0;
      
        for (int i = 0; i < len; i++)
            if (i % k != 0) arr[w++] = arr[i];
        len = w;
    }
  
    free(arr);
    ready = 1;
}
​
long long sum_ludic(int n)
{
    if (n <= 0) return 0;
    if (!ready) build();           // sieve runs once, on the first call ever
    return prefix[n];
}