export class Kata {
  static disemvowel(str: string): string {
    
    let newStr: string = "";
    for(let i = 0; i<str.length;i++)
    {
      let val = str[i].toLowerCase();
      
      if (val != 'a' && val != 'e' && val != 'i' && val != 'o' && val != 'u')
      {
        newStr += str[i];
        
      }
    }
    return newStr;
  }
}
