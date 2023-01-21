function partsSums(ls) {
  const sumsOfParts = [0];
  for(let i = ls.length - 1; i>=0; i--){
    sumsOfParts.push(ls[i] + sumsOfParts[sumsOfParts.length-1]);
  }
  return sumsOfParts.reverse();
}