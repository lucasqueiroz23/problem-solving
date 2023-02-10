function findAverage(array) {
  return array.length === 0 ? 0 : array.reduce((acc,cur)=>acc+=cur, 0)/array.length;
}