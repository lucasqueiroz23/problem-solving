const goodWorth = {
  0: 1,
  1: 2,
  2: 3,
  3: 3,
  4: 4,
  5: 10
}
  
const evilWorth = {
  0: 1,
  1: 2,
  2: 2,
  3: 2,
  4: 3,
  5: 5,
  6: 10
}

function getBattleResult(goodWorthSum, evilWorthSum){
  if (goodWorthSum > evilWorthSum)
    return "Battle Result: Good triumphs over Evil";
  if (goodWorthSum < evilWorthSum)
    return "Battle Result: Evil eradicates all trace of Good";
  
  return "Battle Result: No victor on this battle field";
}

function getWorthSum(side){
  side = side.split(' ');
  let totalWorth = 0;
  const numOfKeys = Object.keys(side).length;
  for(const worth in side){
    if(numOfKeys == 6)
      totalWorth += goodWorth[worth] * parseInt(side[worth]);
    else
      totalWorth += evilWorth[worth] * parseInt(side[worth]);
  }
  
  return totalWorth;
}

function goodVsEvil(good, evil){
  
  const goodWorthSum = getWorthSum(good);
  const evilWorthSum = getWorthSum(evil);
  return getBattleResult(goodWorthSum, evilWorthSum);
}
