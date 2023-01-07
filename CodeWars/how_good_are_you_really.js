function betterThanAverage(classPoints, yourPoints) {
  let sum = 0;
  classPoints.forEach((score) => sum += score);
  const average = sum/classPoints.length;
  return average < yourPoints ? true : false;
}
