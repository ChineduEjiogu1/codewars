#include <stddef.h>
​
int check_exam(size_t n, const char answers[n], const char student[n]) 
{
​
    //  <----  hajime!
  
    int score = 0;
  
  
    for (size_t i = 0; i < n; i++) 
    {
        if (student[i] == ' ')
        {
            
        }
      
        else if (student[i] == answers[i]) 
        {
            score += 4;
        }
      
        else
        {
            score -= 1;
        }  
        
    }
  
    if (score < 0) 
    {
        return 0;
    }
  
    return score;
​
}