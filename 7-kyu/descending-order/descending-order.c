#include <inttypes.h>
​
uint64_t descendingOrder(uint64_t n)
{
    int array[1000000] = {0};
  
    int j = 0;
    int i = 0;
  
    uint64_t result = 0;
   
    int counter_of_digits = 0;
  
    while (n > 0) 
    {
        int digit = n % 10;
        array[j++] = digit;
        counter_of_digits++;
        n /= 10;
    }
  
  for (int i = 0; i < counter_of_digits; i++) 
  {
      for (int j = i + 1; j < counter_of_digits; j++) 
      {
          if (array[i] < array[j]) 
          {
              int temp = array[i];
              array[i] = array[j];
              array[j] = temp;
          }
      }
  }
  
  for (int i = 0; i < counter_of_digits; i++) 
  {
      result = result * 10 + array[i];
  }
    
    return result;
}