export function tribonacci([a, b, c]: [number, number, number], n: number): number[] {
  
  let ar: number[] = [a,b,c];
  
  let j = 0;
  let k = 1;
  let m = 2;
  
  let sum: number = 0;
  
  
  for(let i = 3; i < n;i++)
  {
    
    sum = ar[j] + ar[k] + ar[m];
    ar.push(sum);
    j++;
    k++;
    m++;
    
    sum = 0;
  }
  
  switch(n)
  {
      case 0:
        return [];
      case 1:
        return [a];
      case 2: 
        return [a,b];
      case 3:
        return [a,b,c];
      default:
        return ar;
  }
  
}
