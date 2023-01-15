function positiveSum(arr) {
  let sum = 0;
  arr.forEach((number)=>{
    if(number>0) sum += number;
  })
  return sum;
}