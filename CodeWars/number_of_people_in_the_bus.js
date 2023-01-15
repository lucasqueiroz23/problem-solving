function number(busStops){
  let sum = 0;
  busStops.forEach((stop)=>{
    sum += (stop[0] - stop[1]);
  })
  return sum;
}