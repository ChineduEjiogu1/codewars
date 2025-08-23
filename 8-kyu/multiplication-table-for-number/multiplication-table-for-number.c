#include <stdlib.h>
#include <stdio.h>
#include <string.h>
​
char *multi_table(int num)
{
    int i = 1;
    int result = 0;
    char buffer[200];
  
    char *pos = buffer;
  
    while (i <= 10)
    {
        result = i * num;
​
        if (i < 10) 
        {
            pos += snprintf(pos, buffer + sizeof(buffer) - pos, "%d * %d = %d\n", i, num, result);
        } 
        else 
        {
            pos += snprintf(pos, buffer + sizeof(buffer) - pos, "%d * %d = %d", i, num, result);
        }
​
        i++;
    }
  
    char *result_str = malloc(strlen(buffer) + 1);
    strcpy(result_str, buffer);
  
    return result_str;
}