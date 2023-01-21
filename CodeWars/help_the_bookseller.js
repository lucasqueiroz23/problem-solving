function stockList(listOfArt, listOfCat){
  const categoryBelongings = {};
  
  if(Object.keys(listOfArt).length == 0)
    return '';
  
  for(let item of listOfArt){
    item = item.split(' ');
    const letter = item.at(0).charAt(0);
    const number = parseInt(item.at(1));
    if(letter in categoryBelongings)
      categoryBelongings[letter] += number;
    else
      categoryBelongings[letter] = number;
  }
  
  let res = [];
  
  for(const item of listOfCat){
    if(item in categoryBelongings){
      res.push(`(${item} : ${categoryBelongings[item]})`);
    }
    else
      res.push(`(${item} : 0)`);
  }
  
  res = res.join(' - ');
  return res;
}