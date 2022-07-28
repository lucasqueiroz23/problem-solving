export class Kata {
  static getCount(str: string): number {
    let numberOfVowels: number = 0;
    
    for(let i = 0; i< str.length; i++)
      {
        let letter:string = str[i];
        if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
            numberOfVowels++;
      }
    
    
    return numberOfVowels;
  }
}
