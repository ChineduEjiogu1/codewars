#include <stdbool.h>
#include <string.h>
​
bool scramble(const char *str1, const char *str2)
{ 
    int freq1[256] = {0};
    int freq2[256] = {0};
​
    int str1_length = strlen(str1);
    int str2_length = strlen(str2);
  
    for (int i = 0; i < str1_length; i++)
    {
        freq1[str1[i] - 'a']++;
    }
​
    for (int j = 0; j < str2_length; j++)
    {
        freq2[str2[j] - 'a']++;
    }
    
  for (int k = 0; k < str2_length; k++)
  {
      if (freq1[str2[k] - 'a'] < freq2[str2[k] - 'a']) 
      {
          return false;
      }
  }
  
    return true;
}