class Table{
  multiplicationTable: number[][];
  
  constructor(tableSize: number){
    
    let multiplicationTable: number[][] = [];
    for(let row = 0; row<tableSize; row++){
      
      multiplicationTable.push([]);
      for(let column = 1; column <= tableSize; column++){
        multiplicationTable[row].push(column);
      }
    }
    
    
    this.multiplicationTable = multiplicationTable;
  
  }  
  
  createFullTable(numberToMultiply: number){
    for(let row = 1; row<this.multiplicationTable.length; row++){
      for(let column = 0; column<this.multiplicationTable.length; column++){
        this.multiplicationTable[row][column] *= (row+1); 
      }
    }
    
    
  }
}

export function multiplicationTable (size: number): number[][] {
  let table = new Table(size);
  table.createFullTable(size);
  
  
  return table.multiplicationTable;
}
  
  
  
