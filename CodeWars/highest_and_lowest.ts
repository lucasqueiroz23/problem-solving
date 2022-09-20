export class Kata {
  static highAndLow(numbers: string): string {
    let numArr = numbers.split(' ');
    let highest = numArr[0];
    let lowest = numArr[0];
    for(let i = 1; i < numArr.length;i++){
      if(parseInt(numArr[i]) > parseInt(highest))
        highest = numArr[i];
      if(parseInt(numArr[i]) < parseInt(lowest))
        lowest = numArr[i];
    }
    
    return `${highest} ${lowest}`;
  }
}
