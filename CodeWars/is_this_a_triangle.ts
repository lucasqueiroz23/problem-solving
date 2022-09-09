function sideIsValid(a:number, b:number, c:number):boolean{
  if(a < b + c)
    return true;
  return false;
}

export function isTriangle(a: number, b: number, c: number): boolean {
  if(sideIsValid(a,b,c) && sideIsValid(b,a,c) && sideIsValid(c,b,a))
    return true;
  return false;
}
