export function countBits(n: number): number {
  let numInBinary: string = n.toString(2);
  let bitArr: string[] = numInBinary.split('').sort().reverse();
  let count: number = 0;
  for(let i = 0; i < bitArr.length;i++){
    if(bitArr[i] == '1'){
      count++;
    }
    else break;
  }
  return count;
}
