#include <stddef.h>
#include <stdlib.h>

// return a *new, dynamically allocated* array with each element doubled.
int *maps(const int *arr, size_t size){
  int *doubleArr = malloc(size*sizeof(int));
  for(int i = 0; i< size;i++){
    doubleArr[i] = 2*arr[i];
  }
  
  return doubleArr;
}
