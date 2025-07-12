#include <stdbool.h>

bool validateSudoku(const int board[9][9]) 
{ 
   int freq[10] = {0};
     
   for (int i = 0; i < 9; i++) 
   {
       for (int k = 0; k < 10; k++)
       {
           freq[k] = 0;
       }
       
       for (int j = 0; j < 9; j++) 
       {
           freq[board[i][j]]++;
       }
     
       for (int digit = 1; digit <= 9; digit++) 
       {
           if (freq[digit] != 1) 
           {
               return false;
           }
       }
     
       if (freq[0] > 0)
       {
           return false;
       }
   }
   
   for (int i = 0; i < 9; i++) 
   {
       for (int k = 0; k < 10; k++)
       {
           freq[k] = 0;
       }
   
       for (int j = 0; j < 9; j++) 
       {
           freq[board[j][i]]++;
       }
 
       for (int digit = 1; digit <= 9; digit++) 
       {
           if (freq[digit] != 1) 
           {
               return false;
           }
       }
 
       if (freq[0] > 0)
       {
           return false;
       }
   }
   
   for (int box_row = 0; box_row < 3; box_row++) 
   {
       for (int box_col = 0; box_col < 3; box_col++) 
       {
           for (int k = 0; k < 10; k++)
           {
               freq[k] = 0;
           }
         
           int start_row = box_row * 3;
           int start_col = box_col * 3;
           
           for (int i = start_row; i < start_row + 3; i++) 
           {
               for (int j = start_col; j < start_col + 3; j++) 
               {
                   freq[board[i][j]]++;
               }
           }
           
           for (int digit = 1; digit <= 9; digit++) 
           {
               if (freq[digit] != 1) 
               {
                   return false;
               }
           }
           
           if (freq[0] > 0)
           {
               return false;
           }
       }
   } 
     
   return true;
}
