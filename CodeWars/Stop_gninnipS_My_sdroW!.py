class WordSpin:
    
    def __init__(self,string):
        self.string = string
    
    def spins_word(self):
        
        spinned_word = ""
        
        each_word_separately = self.string.split()
        i = 0
        
        for word in each_word_separately:
            new_word = word
            
            if len(word) >= 5:
                new_word = self.get_reverse_word(word)
            
            
            if i != len(each_word_separately) - 1:
                new_word+= " "
                
            spinned_word += new_word
            i += 1
            
            
        return spinned_word
        
        
    def get_reverse_word(self,word):
        
        reverse_word = ""
        letter = len(word) - 1
        
        while letter >= 0:
            
            reverse_word += word[letter]
            
            letter -= 1
        
        return reverse_word
    
def spin_words(sentence):
    wordSpin = WordSpin(sentence)
    return wordSpin.spins_word()
