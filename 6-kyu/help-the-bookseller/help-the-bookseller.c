#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
​
char *stockSummary(
    const char *const books[/* n_books */], size_t n_books,
  const char *const categories[/* n_categories */], size_t n_categories
) {
  
   if (n_books == 0 || n_categories == 0) 
   {
          char *empty = malloc(1);
          if (empty) empty[0] = '\0';
          return empty;
    }
​
    int *counts = calloc(n_categories, sizeof(int));
    if (!counts) return NULL;
​
    for (size_t i = 0; i < n_books; i++) 
    {
        if (!isalpha((unsigned char)books[i][0])) continue;
​
        const char *sp = strrchr(books[i], ' ');
        int quantity = sp ? atoi(sp + 1) : 0;
​
        char book_category = books[i][0];
        
        for (size_t j = 0; j < n_categories; j++) 
        {
            if (categories[j][0] == book_category) 
            {
                counts[j] += quantity;
                break;
            }
        }
    }
​
    size_t cap = n_categories * 32 + 1;
    char *out = malloc(cap);
    if (!out) { free(counts); return NULL; }
​
    size_t pos = 0;
    for (size_t j = 0; j < n_categories; j++) {
        pos += snprintf(out + pos, cap - pos, "%s(%c : %d)",
                        j ? " - " : "", categories[j][0], counts[j]);
    }
​
    free(counts);
    return out;
}