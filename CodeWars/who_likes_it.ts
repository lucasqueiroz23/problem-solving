export const likes = (a : string[]) : string => {
  let qtdNomes: number = a.length;
  if(qtdNomes >= 4)
  {
    let pplCount: number = qtdNomes - 2;
    let str: string = "";
    
    str += a[0];
    str += ", ";
    str += a[1];
    str += " and "+ pplCount.toString() + " others like this";
    
    return str;
    
  }
  
  if(qtdNomes == 3)
  {
    let str: string = "";
    
    str += a[0];
    str += ", ";
    str += a[1];
    str += " and " + a[2] +" like this";
    
    return str;
    
  }
  
   if(qtdNomes == 2)
  {
    let str: string = "";
    
    str += a[0];
    str += " and ";
    str += a[1];
    str += " like this";
    
    return str;
    
  }
  
   if(qtdNomes == 1)
  {
    let str: string = "";
    
    str += a[0];
    str += " likes this";
    
    return str;
    
  }
  
  return "no one likes this";
  
  
}
