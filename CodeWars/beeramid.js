// Returns number of complete beeramid levels
const beeramid = function(bonus, price) {
  const totalBeers = Math.floor(bonus/price);
  let pos = 1;
  let sum = 0;
  while(sum < totalBeers ){
    sum += pos*pos;
    pos++;
    if(pos * pos + sum > totalBeers)
      break;
  }
  return pos - 1;
}