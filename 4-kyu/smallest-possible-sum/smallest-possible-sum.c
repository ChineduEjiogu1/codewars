#include <stddef.h>
​
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
       
    return gcd(b, a % b);
}
    
int smallest_possible_sum(size_t n, const int array[n]) 
{
    //  <----  hajime!
    int result = array[0];
  
    for (int i = 1; i < n; i++)
    { 
         result = gcd(result, array[i]);
      
         if (result == 1) 
         {
            return 1 * n;
         }
    }
  
    return result * n;   
}