function sumIntervals(intervals) {
  //TODO
  
  let total = 0;
  let R = -Infinity;
  
  intervals.sort((a, b) => a[0] - b[0]);
  
  for (const [s, e] of intervals) {
    total += Math.max(0, e - Math.max(s, R));
    R = Math.max(R, e);
  }
  
  return total; 
}