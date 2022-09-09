def to_camel_case(text):
    
    last_character_was_dash_or_underscore = False
    new_text = ""
    
    for char in text:
        if char  == '-' or char == '_':
            last_character_was_dash_or_underscore = True
            continue
        if last_character_was_dash_or_underscore:
            new_text+=char.upper()
            last_character_was_dash_or_underscore = False
        else:
            new_text+=char
            
    return new_text
