const numberDivides3or5 = (number: number) =>{
  if(numberDivides3(number) || numberDivides5(number))
    return true;
  return false;
}

const numberDivides3 = (number: number) =>{
  if(number%3 == 0)
    return true;
  return false;
}

const numberDivides5 = (number: number) =>{
  if(number%5 == 0)
    return true;
  return false;
}

export class Challenge {
  static solution(maxValue: number) {
    let sumOfMultiples: number = 0;
    
    for(let number = 0; number < maxValue; number++){
      if(numberDivides3or5(number))
        sumOfMultiples+=number;
    }
    
    return sumOfMultiples;
  }

  
}
