#include <math.h>
​
long long multiply_by_sequence(long long n)
{
    int sequence[] = {1, 10, 9, 12, 3, 4};
    int size = sizeof(sequence) / sizeof(sequence[0]);
  
    long long sum = 0;
    int i = 0;
  
    if (n == 0)
    {
        return 0;
    }
    else
    {
        while (n > 0)
        {
            int digit = n % 10;
            sum += digit * sequence[i % size];
            n = n / 10;   
            i++;
        }  
    }
  
  return sum;
}
​
long long thirt(long long n)
{
    // your code
  long long previous_result = multiply_by_sequence(n);
  long long current_result = multiply_by_sequence(previous_result);
  
  while (current_result != previous_result)
  {
      previous_result = current_result;
      current_result = multiply_by_sequence(previous_result);
  }
  
  return previous_result;
}