def first_non_consecutive(arr):
    aux = arr[0]
    
    for number in arr:
        if number == aux:
            continue
        if number - 1 not in arr:
            return number
    
    return None
