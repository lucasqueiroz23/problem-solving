export class Kata {
  static dnaStrand(dna: string) {
    
    let finalStr: string = "";
    for(let i = 0; i<dna.length;i++)
    {
        if(dna[i] == 'A')
          finalStr+='T';
      
        if(dna[i] == 'T')
          finalStr+='A';
        
        if(dna[i] == 'C')
          finalStr+='G';
      
        if(dna[i] == 'G')
          finalStr+='C';
      
    }
  
    return finalStr;
  }
}
