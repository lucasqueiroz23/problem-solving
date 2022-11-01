#include <cmath>


long int findNextSquare(long int sq) {
  long int root = (long int) sqrt(sq);
  
  return (root * root == sq) ? (root + 1) * (root + 1) : -1;
  
}
