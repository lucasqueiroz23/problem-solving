export function accum(s: string): string {
  let letters: string[] = s.split('');
  for(let i = 0; i < letters.length; i++){
    let auxStr: string = '';
    for(let j = 1; j<=i; j++){
      auxStr+=letters[i].toLowerCase();
    }
    letters[i] = letters[i].toUpperCase() + auxStr;
  }
  
  return letters.join('-');
}
