#include <stddef.h>
#include <string.h>
#include <stdlib.h> 
​
char *reverse_words (const char *words, size_t length, char *reversed)
{
/*
'words' is nul-terminated, but its length is given for convenience.
Write to 'reversed' and return it.
*/
  
  int words_length = strlen(words);
  char *words_string = (char *)calloc(words_length + 1, sizeof(char));
  strcpy(words_string, words);
  
  int max_words = words_length / 2 + 1;
  
  char **words_array = malloc(max_words * sizeof(char *));
  
  char *token = strtok(words_string, " ");
  
  int words_count = 0;
  
  reversed[0] = '\0';
  
  while (token != NULL) 
  { 
      words_array[words_count] = token;
      words_count++;
    
      token = strtok(NULL, " ");
  }
  
  for (int i = words_count - 1; i >= 0; i--)
  {
       strcat(reversed, words_array[i]);
    
       if (i > 0) 
       {
          strcat(reversed, " ");
       }
  }
  
  return reversed;
  
}