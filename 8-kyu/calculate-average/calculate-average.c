double find_average(const double array[/* length */], unsigned length)
{
  double average = 0;
  double sum = 0;
  
  if (length == 0)
  {
      return 0;
  }
  
  for (int i = 0; i < length; i++)
  {
      sum += array[i];
  }
  
  average = sum / length;
  
  return average;
}