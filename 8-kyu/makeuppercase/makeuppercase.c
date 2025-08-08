#include <ctype.h>
char *makeUpperCase (char *string)
{
  // write to string and return it
  
  for (int i = 0; string[i] != '\0'; i++)
  {
    string[i] = toupper(string[i]);
  }
  
  return string;
}
​