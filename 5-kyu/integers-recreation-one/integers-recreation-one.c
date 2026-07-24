#include <stdlib.h>
#include <math.h>
#include <stdio.h>
​
typedef struct Pair Pair;
​
struct Pair {
    long long first;
    long long snd;
};
​
static void free_pair_list(Pair **list, int n_pairs) 
{
    while (n_pairs > 0) free(list[--n_pairs]);
  
    free(list);
}
​
Pair **listSquared(long long m, long long n, int *length) {
  
    *length = 0;
  
    if (n < m) return NULL;
​
    Pair **results = malloc((size_t)(n - m + 1) * sizeof *results);
  
    if (!results) return NULL;
​
    int n_found = 0;
​
    for (long long candidate = m; candidate <= n; candidate++) 
    {
        long long square_sum = 0;
​
        for (long long divisor = 1; divisor * divisor <= candidate; divisor++) 
        {
            if (candidate % divisor != 0) continue;
​
            square_sum += divisor * divisor;
​
            long long cofactor = candidate / divisor;
          
            if (cofactor != divisor) square_sum += cofactor * cofactor;
        }
​
        long long root = (long long)round(sqrt((double)square_sum));
      
        if (root * root != square_sum) continue;
​
        Pair *match = malloc(sizeof *match);
      
        if (!match) { free_pair_list(results, n_found); return NULL; }
​
        *match = (Pair){ .first = candidate, .snd = square_sum };
      
        results[n_found++] = match;
    }
​
    if (n_found == 0) { free_pair_list(results, 0); return NULL; }
​
    *length = n_found;
  
    return results;
}