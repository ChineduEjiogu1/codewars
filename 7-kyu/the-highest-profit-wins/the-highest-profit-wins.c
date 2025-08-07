void min_max (const int arr[/* count */], int count, int *min, int *max)
{
// assign to the min and max pointers
  
  int check_min = arr[0];
  int check_max = arr[0];
  
  for (int i = 0; i < count; i++)
  {
      if (arr[i] < check_min) 
      {
          check_min = arr[i];
      }
​
      if (arr[i] > check_max) 
      {
          check_max = arr[i];
      }
  }
  
    *min = check_min;
    *max = check_max; // fix me!
}