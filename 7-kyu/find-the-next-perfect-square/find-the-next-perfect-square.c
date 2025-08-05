#include <math.h>
​
long int findNextSquare(long int sq)
{
    long int current_perfect_square = sq;
  
    long int n = (long int)sqrt(current_perfect_square);
  
    long int next_perfect_square = (n + 1) * (n + 1);
  
    if (n * n == current_perfect_square)
    {
        return next_perfect_square;
    }
  
    else
    {
        return -1;
    }
}