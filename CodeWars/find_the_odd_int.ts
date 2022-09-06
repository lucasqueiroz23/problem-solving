export const findOdd = (xs: number[]): number => {
  
  xs.sort();
  let count: number = 1;
  let num = xs[0];
  
  for(let i = 1; i < xs.length; i++){
    if(xs[i-1] != xs[i]){
      if(count%2 !=0 )
        return xs[i-1];
      count = 1;
    }
    else
      count++;
  }
  
   return xs[xs.length-1];
  
};
