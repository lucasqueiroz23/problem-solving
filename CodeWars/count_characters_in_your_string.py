def count(string):
    str_dict = {}
    
    for letter in string:
        if letter not in str_dict:
            str_dict.update({letter:1})
        else:
            str_dict[letter] += 1
            
    return str_dict
