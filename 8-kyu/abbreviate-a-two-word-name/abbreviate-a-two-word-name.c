#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
​
char *get_initials (const char *full_name, char initials[4])
{
  
    int length = strlen(full_name);
    char *destination = (char *)malloc(length + 1);
    strcpy(destination, full_name);
  
    char second_char = ' ';
    
    for (int i = 0; i < length; i++)
    {
        if (destination[i] == ' ')
        {
            second_char = destination[i + 1];
        }
        
        char first_char = destination[0];
      
        initials[0] = toupper(first_char);
        initials[1] = '.';
        initials[2] = toupper(second_char);
    }
  
  initials[3] = '\0'; // write to initials
  
  return initials; // return it
}