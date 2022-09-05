export function narcissistic(value: number): boolean {
  let numOfDigits: number = 0;
  let auxValue: number = value;
  
  while(Math.floor(auxValue) > 0){
    numOfDigits++;
    auxValue/=10;
  }
  
  auxValue = value;
  
  
  let sumOfDigits: number = 0;
  for(let i = 1; i<= numOfDigits; i++){
    
    let val = auxValue%10;
    sumOfDigits += val**numOfDigits;
    auxValue = Math.floor(auxValue/10);  
  }
  
  
  
  if(sumOfDigits == value)
    return true;
  
  return false;
  
}
