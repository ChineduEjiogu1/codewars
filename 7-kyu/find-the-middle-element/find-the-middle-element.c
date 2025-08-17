int gimme (const int triplet[3])
{
    int index = 0;
  
    int min = triplet[0];
    int max = triplet[0];
​
    for (int i = 1; i < 3; i++) 
    {
        if (triplet[i] < min)
        {
            min = triplet[i];
        }
        if (triplet[i] > max) 
        {
            max = triplet[i];
        }
    }
  
    for (int i = 0; i < 3; i++) 
    {
        if (triplet[i] != min && triplet[i] != max) 
        {
            index = i;
        }
    }
    
    return index;
}