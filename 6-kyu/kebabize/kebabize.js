function kebabize(str) {
  // TODO
  let resultString = '';
  
  for (const s of str) {
    
    if (s >= 'A' && s <= 'Z') {
      
      if (resultString !== "") {
        
        resultString += '-';
      }
      
      resultString += s.toLowerCase();
      
    } else if (s >= 'a' && s <= 'z') {
      
      resultString += s;    
    } 
  }
  
  return resultString;
}