#include <stdlib.h>
#include <string.h>
​
size_t count_words (const char *words)
{
// count the number of words
// this function will be used to allocate the right amount of memory so it has to be correct !
  
    size_t length = strlen(words);
    char *destination = (char *)malloc(length + 1);
    strcpy(destination, words);
  
    size_t counter = 0;
    
    char *token = strtok(destination, " ");
​
    // Loop through the string to extract all subsequent tokens
    while (token != NULL) 
    {
        counter++;
        token = strtok(NULL, " ");
    }
    
    return counter;
}
​
void words_to_array (const char *words, char *words_array[])
{
// allocate the words on the heap, they will be freed
// write them to the pre-allocated words_array
  
    size_t length = strlen(words);
    char *destination = (char *)malloc(length + 1);
    strcpy(destination, words);
  
    char *token = strtok(destination, " ");
  
    int i = 0;
  
    while (token != NULL) 
    {
        char *save_tokens = (char *)malloc(strlen(token) + 1);
        strcpy(save_tokens, token);
        words_array[i] = save_tokens;
        i++;
        token = strtok(NULL, " ");
    }
  
  free(destination);
}