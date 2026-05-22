function isValidIP(str) {
  
  let listOfOctets = str.split('.');
  
  if (listOfOctets.length !== 4) {
    return false;
  }
  
  for (const individualOctet of listOfOctets) {
    
    
    if (individualOctet === "") {
      return false;
    }
    
    if (![...individualOctet].every(ch => ch >= '0' && ch <= '9')) {
      return false;
    }
    
    if (individualOctet[0] === '0' && individualOctet.length > 1) {
      return false;
    }
    
    if (Number(individualOctet) > 255) {
      return false;
    }
    
  }
  
  return true;
}