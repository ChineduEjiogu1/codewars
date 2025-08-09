#include <stddef.h>
#include <string.h>
​
int stray(size_t n, int arr[n]) 
{
​
    //  <----  hajime!
  
    int check_min = arr[0];   
    int check_max = arr[0];
   
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] < check_min) 
        {
            check_min = arr[i];
        }
​
        if (arr[i] > check_max) 
        {
            check_max = arr[i];
        }
    }
  
    int freq[check_max - check_min + 1];
  
    memset(freq, 0, sizeof(freq)); 
  
    for (size_t i = 0; i < n; i++) 
    {
        freq[arr[i] - check_min]++;
    }
  
    for (int i = 0; i < (check_max - check_min + 1); i++) 
    {
        if (freq[i] == 1) 
        {
            return i + check_min;
        }
    }
  
  return 0;
}