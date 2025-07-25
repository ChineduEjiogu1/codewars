#include <string.h>
​
int roman_value(char roman_char) 
{
    switch (roman_char) 
    {
      case 'I':
          return 1;
      case 'V':
          return 5;
      case 'X':
          return 10;
      case 'L':
          return 50;
      case 'C':
          return 100;
      case 'D':
          return 500;
      case 'M':
          return 1000;
      default:
          return 0;
    }
}
​
unsigned from_roman (const char *roman)
{
    int string_length = strlen(roman);
    int roman_sum = 0;
    int i = 0;
  
    while (i < string_length) 
    {
        int current_value = roman_value(roman[i]);
      
        if (i < string_length - 1) 
        {
            int next_value = roman_value(roman[i + 1]);
          
            if (current_value < next_value) 
            {
                roman_sum += next_value - current_value;
                i += 2;  