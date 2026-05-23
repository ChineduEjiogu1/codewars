function abbreviate(string) {
  // ...
  
  return string.replace(/[a-zA-Z]+/g, (word) => { 
    if (word.length >= 4) {
     return word[0] + (word.length - 2) + word[word.length - 1];  
    }
      return word;
  });
}