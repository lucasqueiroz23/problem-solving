function solution(str, ending){
  return str.substring(str.length - ending.length, str.length) === ending ? true : false;
}
