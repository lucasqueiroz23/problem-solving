#include <stdlib.h>

unsigned short *reverse_seq(unsigned short num)
{
  unsigned short *ar = malloc(num*sizeof(unsigned short));
  
  int i = 0;
  while(num>0)
  {
    ar[i] = num; 
    
    i++;
    num--;
  }
  
  return ar;
}
