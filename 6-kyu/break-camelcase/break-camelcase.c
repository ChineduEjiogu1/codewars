#include <stddef.h> // NULL
#include <string.h>
//returned buffer should be dynamically allocated and will be freed by a caller
char* solution(const char *camelCase) 
{ 
  int length = strlen(camelCase);
  char *result_array = malloc((length * 2 + 1) * sizeof(char));
  
  int j = 0;
  
  for (int i = 0; camelCase[i] != '\0'; i++)
  {  
      if (isupper(camelCase[i]) && i != 0)
      {
          result_array[j++] = ' '; 
      }
    
      result_array[j++] = camelCase[i]; 
  }
  
  result_array[j] = '\0';
  
  return result_array;
}