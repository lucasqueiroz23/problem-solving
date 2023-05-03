#include <stddef.h>

double mean_square_error(size_t n, const int a[n], const int b[n]) {
  double sum = 0;
    for(size_t i = 0; i < n; i++){
      double diff = a[i] - b[i];
      if(diff < 0) diff *= -1;
      sum += diff * diff;
    }
  return sum/n;
}

