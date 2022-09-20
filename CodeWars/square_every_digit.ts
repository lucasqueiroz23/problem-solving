export class Kata {
  static squareDigits(num: number): number {
    let finalStr = '';
    let numStr = num.toString();
    for(let i = 0; i<numStr.length;i++){
      let digit = parseInt(numStr[i]);
      digit*=digit;
      finalStr+=digit.toString();
    }
    
    return parseInt(finalStr);
  }
}
