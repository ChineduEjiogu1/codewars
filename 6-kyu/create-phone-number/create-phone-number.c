#include <stdint.h>
#include <stdio.h>
#include <string.h>
​
char *create_phone_number(char phnum[15], const uint8_t digits[10])
{
    // write to phnum and return it
    // it must be nul-terminated
    
    sprintf(phnum, "(%d%d%d) %d%d%d-%d%d%d%d", digits[0], digits[1], digits[2], digits[3], digits[4], digits[5], digits[6], digits[7], digits[8], digits[9]);
    
    return phnum;
}