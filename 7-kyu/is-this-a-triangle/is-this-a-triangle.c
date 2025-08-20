#include <stdbool.h>
​
bool is_triangle(int a, int b, int c)
{
    if (a + b > c && a + c > b && b + c > a) 
    {
        if (a != b && b != c && a != c) 
        {
            return true;
          
        } 
        else if (a == b && b == c) 
        {
            return true;
        } 
        else 
        {
            return true;
        }
    } 
    else 
    {
        return false;
    }
}