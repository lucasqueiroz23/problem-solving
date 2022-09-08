def move_zeros(lst):
    i = len(lst) - 1;
    while i >= 0:
        if lst[i] == 0:
            posZero = i
            while posZero < len(lst):
                if posZero == len(lst) - 1:
                    break
                
                if lst[posZero+1] == 0:
                    break
                
                temporaryValue = lst[posZero + 1]
                lst[posZero+1] = lst[posZero]
                lst[posZero] = temporaryValue
                
                posZero+=1
        
        i -= 1
    
    return lst
