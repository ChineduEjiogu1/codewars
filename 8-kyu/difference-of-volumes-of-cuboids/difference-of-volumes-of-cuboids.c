#include <stdlib.h>
​
int find_difference(const int a[3], const int b[3]) {
​
    //  <----  hajime!
  
    int product_1 = 1;
    int product_2 = 1;
  
    for (int i = 0; i < 3; i++)
    {
        product_1 *= a[i];
    }
  
    for (int i = 0; i < 3; i++)
    {
        product_2 *= b[i];
    }
  
    return abs(product_1 - product_2);  
}