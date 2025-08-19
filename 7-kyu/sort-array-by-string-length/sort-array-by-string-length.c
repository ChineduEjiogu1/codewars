#include <string.h>
#include <stdlib.h>
​
void sort_by_length (const char *strings[])
{
// strings[] is NULL-terminated
// Re-use the pointers in 'strings', just change their order in the array
// according to their length
  
    int i = 0;
    int j = 0;
    
    int strings_size = 0;
  
    for (i = 0; strings[i] != NULL; i++) 
    {
        strings_size++;
    }
  
    for (i = 0; i < strings_size; i++) 
    {
        for (j = 0; j < strings_size - i - 1; j++) 
        {
            if (strlen(strings[j]) > strlen(strings[j + 1]))
            {
                // Swap token pointers
                char *temp_token = (char *)strings[j];
                ((char **)strings)[j] = (char *)strings[j + 1];
                ((char **)strings)[j + 1] = temp_token;
            }
        }
    }
}