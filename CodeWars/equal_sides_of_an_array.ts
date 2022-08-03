class MyArray{
  
  myList: number[];
  sumOfIntegersToLeftOfIndex: number[];
  sumOfIntegersToRightOfIndex: number[];
  
  constructor(myList: number[], sumOfIntegersToLeftOfIndex: number[] = [], sumOfIntegersToRightOfIndex: number[] = []){
    this.myList = myList;
    this.sumOfIntegersToLeftOfIndex = sumOfIntegersToLeftOfIndex;
    this.sumOfIntegersToRightOfIndex = sumOfIntegersToRightOfIndex;
  }
  
  createSumOfItemsToLeft(){
    
    for(let i = 0; i< this.myList.length; i++){
      
      if(i == 0){
        this.sumOfIntegersToLeftOfIndex.push(0);
        continue;
      }
      
      let sum = this.sumOfIntegersToLeftOfIndex[i-1] + this.myList[i-1];
      this.sumOfIntegersToLeftOfIndex.push(sum);
      
    }
    
  }
    
  createSumOfItemsToRight(){
    
    for(let i = 0; i< this.myList.length; i++)
        this.sumOfIntegersToRightOfIndex.push(0);
    
    for(let i = this.myList.length - 1; i>=0; i--){
      if(i == this.myList.length - 1){
        continue;
      }
      
      let sum = this.sumOfIntegersToRightOfIndex[i+1] + this.myList[i+1];
      this.sumOfIntegersToRightOfIndex[i] = sum;
      
    }
    
  }
  
  getIndexOfEqualSums(){
    
    for(let i = 0; i < this.myList.length; i++){
      if(this.sumOfIntegersToLeftOfIndex[i] == this.sumOfIntegersToRightOfIndex[i])
          return i;
    }
    
    return -1;
  }
  
}

export function findEvenIndex(arr: number[]): number
{
  let array = new MyArray(arr);
  
  array.createSumOfItemsToRight();
  array.createSumOfItemsToLeft();
  
  return array.getIndexOfEqualSums();
  
}
