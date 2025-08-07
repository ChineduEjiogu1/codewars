#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
​
ssize_t find_short(const char *s)
{
    ssize_t length = strlen(s);
    char *destination = (char *)malloc(length + 1);
    strcpy(destination, s);
  
    char *min_word = s;
    
    ssize_t min = strlen(min_word); 
    
    char * myPtr = strtok(destination, " ");
  
    while(myPtr != NULL) 
    {
        ssize_t shortest_string = strlen(myPtr);
      
        if (shortest_string < min) 
        {
            min = shortest_string;
        }
      
      myPtr = strtok(NULL, " ");
    }
  
    return min;
}