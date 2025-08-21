#include <stddef.h>
#include <stdlib.h>
​
//  return a dynamically allocated int array
//  set the pointer sz_out to size of output
//  return array will be freed by the tester
​
int *pipe_fix(size_t sz_in, const int input[sz_in], size_t *sz_out) 
{ 
    //  <----  hajime!
  
    int min = input[0];
  
    int max = input[sz_in - 1];
  
    *sz_out = max - min + 1;
    
    int *result_array = malloc(*sz_out * sizeof(int));
    
    for (size_t i = 0; i < *sz_out; i++)
    {
        result_array[i] = min + i;
    }
  
  return result_array;
}