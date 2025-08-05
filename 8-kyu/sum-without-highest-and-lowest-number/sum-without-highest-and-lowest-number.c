#include <stdlib.h>
#include <stdbool.h>
​
int sum(const int numbers[/*length*/], int length)
{
    bool excluded_min = false;
    bool excluded_max = false;
  
    if (numbers == NULL)
    {
        return 0;
    }
  
    int min = numbers[0];
    int max = numbers[0];
​
    int total_sum = 0;
  
    if (length < 3)
    {
        return 0;
    }
  
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] < min) 
        {
            min = numbers[i];
        }
      
        if (numbers[i] > max) 
        {
            max = numbers[i];
        }
    }
  
    for (int i = 0; i < length; i++) 
    {     
        if (numbers[i] == min && !excluded_min)
        {
            excluded_min = true;
        }
      
        else if (numbers[i] == max && !excluded_max)
        {
            excluded_max = true;
        }
      
        else 
        {
            total_sum += numbers[i];
        }  
    }
    
    return total_sum;
}