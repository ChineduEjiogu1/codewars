function validate(n) {
  
  let creditCard = String(n).split('');
  
  let total = 0;
  let double = 2;
  let forcedBase10 = 9;
  
  for (let i = 0; i < creditCard.length; i++) {
    let creditCardDigit = Number(creditCard[i]);
    if (i % 2 === creditCard.length % 2) {
      creditCardDigit = creditCardDigit * double;
      if (creditCardDigit > 9) {
        creditCardDigit = creditCardDigit - forcedBase10;
      }
    }
    total += creditCardDigit;
  }
  return total % 10 === 0;
}
​