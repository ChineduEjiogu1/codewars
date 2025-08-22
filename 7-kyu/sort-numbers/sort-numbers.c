#include <stddef.h>
​
void sort_ascending (size_t length, int array[length])
{
  // sort the array given in parameter in place
  
    if (length == 0)
    {
        return;
    }
  
    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = i + 1; j < length; j++)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }      
        }
    }
}