export function isValidWalk(walk: string[]) {
  console.log(walk);
  if(walk.length % 2 == 1 || walk.length != 10)
    return false;
  
  let count_horiz: number = 0;
  let count_vert: number = 0;
  
  for(let i = 0; i< walk.length; i++){
    switch(walk[i]){
        case 'n':
          count_vert++;
          break;
        case 's':
          count_vert--;
          break;
        case 'e':
          count_horiz++;
          break;
        case 'w':
          count_horiz--;
          break;
        default:
          break;
    }
  }
  if(count_horiz != 0 || count_vert != 0)
    return false;
  
  return true;
}
