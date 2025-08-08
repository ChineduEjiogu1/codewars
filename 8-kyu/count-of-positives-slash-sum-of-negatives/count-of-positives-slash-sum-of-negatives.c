#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
​
void count_positives_sum_negatives(
  int *values, size_t count, int *positivesCount, int *negativesSum) 
{
  // Please store the positives count in the memory, pointed to
  // by the positivesCount parameter.
  
  // Please store the negatives sum in the memory, pointed to
  // by the negativesSum parameter.
  
  if (values == NULL || count == 0) 
  {
    *positivesCount = 0;
    *negativesSum = 0;
    
    return;
  }
  
  int positive_counter = 0;
  int negative_sum = 0;
  
  int* arr = (int*)malloc(2 * sizeof(int));
  
  for (size_t i = 0; i < count; i++)
  {
      if (values[i] > 0)
      { 
          positive_counter++;
      }
      
      if (values[i] < 0)
      {
          negative_sum += values[i];
      }
  }
  
  *positivesCount = positive_counter;
  *negativesSum = negative_sum;
  
}  