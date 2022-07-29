export const nbYear = (p0:number, percent:number, aug:number, p:number): number => {
  
  percent = percent/100;
  let n: number = 0;
  
  
  while(p0<p)
  {
    p0 = p0 + Math.floor(p0*percent) + aug;
    
    n++;
    
  }
  
  return n;
}
