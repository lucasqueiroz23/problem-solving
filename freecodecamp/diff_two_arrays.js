function diffArray(arr1, arr2) {
  const newArr = [];
  for(let i = 0; i<arr1.length;i++)
  { 
    let element_is_present_in_both_arrays = false;
    
    for(let j = 0; j<arr2.length;j++)
    {
      
      if(arr1[i] == arr2[j])
      {
        element_is_present_in_both_arrays = true;
        break;
      }

    }

    if (!element_is_present_in_both_arrays) newArr.push(arr1[i]);
  }

  for(let i = 0; i<arr2.length;i++)
  { 
    let element_is_present_in_both_arrays = false;
    
    for(let j = 0; j<arr1.length;j++)
    {
      
      if(arr1[j] == arr2[i])
      {
        element_is_present_in_both_arrays = true;
        break;
      }
      
    }

    if (!element_is_present_in_both_arrays) newArr.push(arr2[i]);
  }

  return newArr;
}

diffArray([1, 2, 3, 5], [1, 2, 3, 4, 5]);
