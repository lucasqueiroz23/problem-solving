class StringModifier{
  stringToModify: string;
    
  constructor(stringToModify: string){
    this.stringToModify = stringToModify;
  }
  
  getStringInPigLatin(){
    let eachWordSeparately: string[] = this.stringToModify.split(" ");
    
    let stringInPigLatin: string = "";
    
    for(let i = 0; i < eachWordSeparately.length; i++){
      let word = eachWordSeparately[i];
      //console.log("word = " + word)
      
      if(word == " " || word == "\n"|| word == ""){
        
        if(i != eachWordSeparately.length - 1)
          stringInPigLatin += " ";
        continue;
      }
      
      if(word == "!" || word == "." || word == "?" ){
        stringInPigLatin += word;
        if(i != eachWordSeparately.length-1)
          stringInPigLatin += " ";
        continue;
      }
      
      for(let j = 1;j<word.length;j++)
        stringInPigLatin += word[j];
      
      stringInPigLatin += word[0];
      stringInPigLatin += "ay";
      
      if(i != eachWordSeparately.length-1)
        stringInPigLatin += " ";
    }
    
    return stringInPigLatin;
    
  }
  
}


export const pigIt = (a : string) : string =>  {
  let modifier = new StringModifier(a);
  return modifier.getStringInPigLatin();
  
}
