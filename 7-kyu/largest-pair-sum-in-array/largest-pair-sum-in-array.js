function largestPairSum (numbers) {
  //TODO: Write your Code here
  
    let result = 0;
  
    for (num of numbers) {
      
      sorted_array = numbers.sort((a, b) => a - b);
      
      result = (Math.max(num) + numbers[numbers.length - 2]);
  }
      
  return result;
}