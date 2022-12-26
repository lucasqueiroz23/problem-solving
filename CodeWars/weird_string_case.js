function solve(char, posIsEven){
  if(posIsEven) return char.toUpperCase();
  return char;
}

function toWeirdCase(string){
  let ans = '';
  string  = string.split(' ');
  for(let j = 0; j<string.length; j++){
    for(let i = 0; i < string[j].length; i++)
      ans += solve(string[j].charAt(i), i%2 == 0);
    ans = j == string.length - 1 ? ans : ans + ' ';
  }
  return ans;
}
