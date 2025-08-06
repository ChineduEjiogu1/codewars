#include <string.h>
​
/* remember to null-terminate outp! */
​
char *get_middle(char outp[3], const char *inp)
{
    int string_length = strlen(inp);
  
    int j = 0;
  
    int middle_index = string_length / 2;
 
    if (string_length % 2 == 1)
    {
        outp[0] = inp[middle_index];
        
        outp[1] = '\0';
    }      
​
    else if (string_length % 2 == 0)
    {
        outp[j++] = inp[middle_index - 1];
        outp[j++] = inp[middle_index];
      
        outp[j] = '\0';
    }
  
    return outp;
}