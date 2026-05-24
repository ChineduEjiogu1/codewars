function solution(text, markers) {
  // TODO
  
  let lines = text.split('\n');
  
  let processedLines = lines.map(line => {
      
        let runningMin = line.length;
​
        markers.forEach((marker) => {
​
        const markerIndex = line.indexOf(marker);
​
        if (markerIndex >= 0 && markerIndex < runningMin) {
          runningMin = markerIndex;
        }
​
      });
      
    return line.slice(0, runningMin).trimEnd();
});
    
   return processedLines.join('\n');  
}