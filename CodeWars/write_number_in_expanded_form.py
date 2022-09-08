def expanded_form(num):
    
    num = str(num)
    size = len(num) - 1
    
    expanded_form = ""
    
    for digit in num:
        digit = int(digit)
        
        if digit == 0:
            size-=1
            continue
            
        digit *= 10 ** size
        expanded_form += f"{digit}"
        expanded_form += " "
        size -= 1
    
    expanded_form = expanded_form.rstrip()
    expanded_form_final = expanded_form.split()
    expanded_form = ''
    
    i = 0 
    
    for number in expanded_form_final:
        expanded_form += f"{number}"
        if i < len(expanded_form_final) - 1:
            expanded_form+= ' + '
        
        i+=1
    
    
    return expanded_form
