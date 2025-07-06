#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Morse code lookup table - dots and dashes for each character
const char *const morse[55] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."};  

// Corresponding ASCII characters for each morse code
const char *const ascii[55] = {"A",  "B",    "C",    "D",   "E", "F",    "G",   "H",    "I",  "J",    "K",   "L",    "M",  "N",  "O",   "P",    "Q",    "R",   "S",   "T", "U",   "V",    "W",   "X",    "Y",    "Z",    "0",     "1",     "2",     "3",     "4",     "5",     "6",     "7",     "8",     "9",     ".",      ",",      "?",      "'",      "!",      "/",     "(",     ")",      "&",     ":",      ";",      "=",     "+",     "-",      "_",      "\"",     "$",       "@",      "SOS"};

// Removes leading and trailing spaces while preserving internal spacing
void trim_leading_trailing_spaces(char *string)
{
    int start = 0;
    int end = strlen(string) - 1;
    
    // Find first non-space character from the beginning
    while (start < strlen(string) && isspace(string[start])) {
        start++;
    }
    
    // Find last non-space character from the end
    while (end >= 0 && isspace(string[end])) {
        end--;
    }
    
    // Calculate the length of the trimmed content
    int new_length = end - start + 1;
    
    if (new_length > 0) {
        // Shift the trimmed content to the beginning of the string
        memmove(string, string + start, new_length);
        string[new_length] = '\0';  // Add null terminator
    } else {
        // If string was all spaces, make it empty
        string[0] = '\0';
    }
}

char *decode_morse(const char* morse_code) 
{
     //  <----  hajime!
    // Setup: allocate memory and initialize variables
    int morse_length = strlen(morse_code);
    char *morse_string = (char *)calloc(morse_length + 1, sizeof(char));  // Working copy of input
    char *morse_concat = calloc(morse_length + 50, sizeof(char));          // Result string
    int num_of_elements = sizeof(morse)/sizeof(morse[0]);                  // Size of lookup tables
    char *token;                                                           // For tokenizing morse codes
  
    // Copy input and remove leading/trailing spaces
    strcpy(morse_string, morse_code);
    trim_leading_trailing_spaces(morse_string); 
  
    // Look for first occurrence of 3 consecutive spaces (word boundary)
    char *three_spaces = strstr(morse_string, "   ");
  
    // Process multiple words separated by 3 spaces
    while (three_spaces) 
    {
        // Split at the 3-space boundary
        *three_spaces = '\0';                    // Terminate first word
        char *word1 = morse_string;              // Points to first word
        char *word2 = three_spaces + 3;          // Points to remaining text after 3 spaces
      
        // Process first word: split by single spaces and decode each morse code
        char *saveptr1;
        token = strtok_r(word1, " ", &saveptr1);
        while (token != NULL) 
        { 
            // Look up current morse code in the lookup table
            for (int i = 0; i < num_of_elements; i++)
            {
                if (strcmp(token, morse[i]) == 0)
                {
                    strcat(morse_concat, ascii[i]);  // Add corresponding character to result
                }
            }
            token = strtok_r(NULL, " ", &saveptr1);  // Get next morse code in this word
        }
        
        // Add space between words in the output
        strcat(morse_concat, " ");
      
        // Update for next iteration: make remaining text the new string to process
        morse_string = word2;
        three_spaces = strstr(morse_string, "   ");  // Look for more 3-space sequences
    } 
    
    // Process the final remaining word (no more 3-space sequences found)
    token = strtok(morse_string, " ");
    while (token != NULL) 
    { 
        // Look up morse code and add corresponding character to result
        for (int i = 0; i < num_of_elements; i++)
        {
            if (strcmp(token, morse[i]) == 0)
            {
                strcat(morse_concat, ascii[i]);
            }
        }
        token = strtok(NULL, " ");  // Get next morse code
    }
  
    return morse_concat;  // Return the decoded string
}
