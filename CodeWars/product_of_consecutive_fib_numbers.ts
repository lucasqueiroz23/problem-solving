export const productFib = (prod:number): [number,number,boolean] => {
  
  let prodFound: boolean = false;
  
  let f_n: number = 1;
  let f_n_1: number = 0;
  
  let fib: number = f_n + f_n_1;
  
  let result: [number,number,boolean] = [1,1,true];
  
  while(!prodFound){  
    
    f_n_1 = f_n;
    f_n = fib;
    
    if(f_n_1*f_n == prod){
      prodFound = true;
      break;
    }
    
    if(f_n_1*f_n > prod){
      break;
    }
    
    fib = f_n + f_n_1;
  }
  
  result[0] = f_n_1;
  result[1] = f_n;
  if(prodFound){
    result[2] = true;
  }
  else
    result[2] = false;
  
  return result;
}
