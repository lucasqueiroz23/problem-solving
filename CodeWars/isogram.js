function isIsogram(str){
  str = str.toLowerCase().split('');
  
  const letters = {};
  
  for(const char of str){
    if(char in letters){
        return false;
    }
    else
      letters[char] = 1;
  }
  return true;
}