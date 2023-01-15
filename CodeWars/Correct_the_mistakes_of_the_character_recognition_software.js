function checkIfCharIsCorrect(char){
  const mistakes = {
    '0': 'O',
    '5': 'S',
    '1': 'I'
  }
  return char in mistakes ? mistakes[char] : char;
}

function correct(string){
  let correctedString = '';
  
  string.split('').forEach((char)=>{
    correctedString+=checkIfCharIsCorrect(char);
  });
  
  return correctedString;
}