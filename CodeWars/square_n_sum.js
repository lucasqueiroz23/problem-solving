function squareSum(numbers){
  return numbers.map((number)=>number*number).reduce((acc,cur)=>acc+cur, 0);
}