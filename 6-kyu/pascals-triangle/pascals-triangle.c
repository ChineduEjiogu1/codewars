long long factorial(int num) 
{
  long long fact = 1;
​
  for (int i = 1; i <= num; i++) 
  {
      fact *= i;
  }
​
  return fact;
} 
​
long long combination(int n, int k)
{
    if (k < 0 || k > n) return 0;
  
    if (k > n - k) 
      k = n - k;              // symmetry: nCk == nC(n-k), pick smaller
  
    long long result = 1;
  
    for (int i = 0; i < k; i++)
        result = result * (n - i) / (i + 1);
  
    return result;
}
​
void pascals_triangle(unsigned n, unsigned triangle[n * (n + 1) / 2])
{
    unsigned index = 0;          // flat write position
  
    for (unsigned r = 0; r < n; r++)          // each row
        for (unsigned c = 0; c <= r; c++)     // each entry in that row
            triangle[index++] = combination(r, c);
}