#include <stddef.h>
#include <stdlib.h>
​
int *maps(const int *arr, size_t size) 
{
  // return a *new, dynamically allocated* array with each element doubled.
  int *result_array = malloc(size * sizeof(*arr));
  int double_number = 2;
  
  for (int i = 0; i < size; i++)
  {
      result_array[i] = double_number * arr[i];
  }
  
  return result_array;
}