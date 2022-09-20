export function descendingOrder(n: number): number {
  let eachNumberSeparately : number[] = [];
  let auxStr: string = n.toString();
  for(let i = 0; i<auxStr.length; i++){
    eachNumberSeparately.push(parseInt(auxStr[i]));
  }
  auxStr = '';
  eachNumberSeparately.sort().reverse();
  for(let i = 0; i <eachNumberSeparately.length; i++)
    auxStr+=eachNumberSeparately[i].toString();
  return parseInt(auxStr);
}
