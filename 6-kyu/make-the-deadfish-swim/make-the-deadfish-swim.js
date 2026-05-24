function parse( data )
{
    let value = 0;
    let result = [];
​
    for (let num of data) {
​
        switch (num) {
​
        case 'i':
          value++;
          break;
        case 'd':
          value--;
          break;
        case 's':
          value **= 2;
          break;
        case 'o': result.push(value); 
          break; 
      }
    }
  
  return result;
}