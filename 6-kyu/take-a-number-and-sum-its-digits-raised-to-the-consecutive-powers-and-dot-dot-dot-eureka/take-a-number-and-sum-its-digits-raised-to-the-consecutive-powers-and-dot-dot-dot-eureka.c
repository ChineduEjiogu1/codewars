//  don't allocate memory for the results array
//  assign values to the provided results array
//  set length pointer as size of results array
//  after calculations return the results array
​
#include <stddef.h>
#include <math.h>
​
typedef unsigned long long ull;
​
#define MAX_SIZE 100
​
int split_digits(int num, int *result, int *digits)
{
    int index = 0;
    int digits_count = 0;
    int j = 0;
  
    while (num > 0) 
    {
        int digit = num % 10;
        digits[index++] = digit;
        digits_count++;
        num /= 10;
    }
  
    for (int i = digits_count; i > 0; i--) 
    {
        result[j++] = digits[i - 1];
    }
  
    return digits_count;
}
​
ull *sum_dig_pow(ull a, ull b, ull *results, size_t *length) 
{   
    //  <----  hajime!
    int digits_temp[MAX_SIZE];
    int final_digits[MAX_SIZE];
  
    *length = 0;
  
    int sum = 0;
  
    int j = 0; 
  
    for (ull num = a; num <= b; num++)
    {
        sum = 0;
      
        int count = split_digits(num, final_digits, digits_temp);
      
        for (size_t i = 0; i < count; i++) 
        {
            sum += pow(final_digits[i], i + 1);
        } 
      
        if (sum == num)
        {
            results[j++] = num;
            (*length)++;
        }
    }
  
    return results;
}