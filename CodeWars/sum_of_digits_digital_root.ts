export const digitalRoot = (n:number):number => {
  let sum = 10;
  while(sum>9){
    let numArray =  n.toString().split('');
    sum = 0;
    for(let i = 0; i< numArray.length; i++){
      sum+= parseInt(numArray[i]);
    }
    if(sum>9)
      n = sum;
  }
  
  return sum;
};
