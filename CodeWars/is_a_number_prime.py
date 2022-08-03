import math

def is_prime(num):
    divisors = 1
    if num == 0 or num == 1 or num < 0 : 
        return False
    
    for i in range(2,int(math.sqrt(num)) + 1):
        if num%i == 0:
            return False
    
    
    return True
    
