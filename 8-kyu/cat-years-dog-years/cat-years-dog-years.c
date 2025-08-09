#include <stdlib.h>
​
typedef struct Human_Cat_Dog_Years {
    unsigned human_years, cat_years, dog_years;
} years;
​
years human_years_cat_years_dog_years(unsigned human) {
​
    //  <----  hajime!
  
    unsigned cat_years_value = 0;
    unsigned dog_years_value = 0;
    unsigned human_years_value = human;
  
    struct Human_Cat_Dog_Years result;
  
    if (human <= 1)
    {
        cat_years_value = 15;
    }
    else if (human == 2)
    {
        cat_years_value = 15 + 9;
    }
    else
    {
        cat_years_value = 15 + 9 + ((human - 2) * 4);
    }
    
    if (human <= 1)
    {
        dog_years_value = 15;
    }
    else if (human == 2)
    {
        dog_years_value = 15 + 9;
    }
    else 
    {
        dog_years_value = 15 + 9 + ((human - 2) * 5);
    }
  
    result.human_years = human_years_value;
    result.cat_years = cat_years_value;
    result.dog_years = dog_years_value;
    
    return result;
}