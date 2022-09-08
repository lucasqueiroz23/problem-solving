def duplicate_count(text):
    
    repetitions = dict()
    repeated = dict()
    count = 0
    
    for letter in text:
        letter = letter.lower()
        if letter in repetitions:
            repetitions[letter] += 1
            
            if letter not in repeated:
                repeated.update({letter:1})
                count+=1
        else:
            repetitions.update({letter: 1})
    
    
    return count
        
     
