function zeros (n) {
  // your code here
  
  let sum = 0;
  let k = 1;
  
  while (5 ** k <= n) {
    
    sum += Math.floor(n / 5**k)
    
    k++
  } 
  return sum;
}