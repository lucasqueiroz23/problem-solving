def create_phone_number(phone_number_list):
    phone_number = "("
    j = 0
    for number in phone_number_list:
        
        number = str(number)
        phone_number += number
        
        if j == 2:
            phone_number+= ") "
        if j == 5:
            phone_number += "-"
            
        j += 1

    return phone_number
