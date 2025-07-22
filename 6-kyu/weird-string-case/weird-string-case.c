#include <ctype.h>
​
char *to_weird_case (char *string)
{
  // mutate string and return it
  
  int j = 0;
  
  for (int i = 0; string[i] != '\0'; i++)
  {
      if (string[i] == ' ')
      {
          j = 0;
          continue;    
      }
    
      if (j % 2 == 0)
      {
          string[i] = toupper(string[i]);
      }
      else
      {
          string[i] = tolower(string[i]);
      }
    
      j++;
  }    
    
  return string;
}