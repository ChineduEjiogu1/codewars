#include <math.h>
#include <stdlib.h>
​
int round_to_next5(int n) 
{
    //  <----  hajime!
    int multiple = 5;
    int result = 0;
  
    if (n % multiple == 0)
    {
        result = n;
    }
    else
    {
        result = (int)ceil(n / 5.0) * multiple;
    }
  
    return result;
}