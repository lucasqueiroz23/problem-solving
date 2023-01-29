#include <iostream>

int a, b;

unsigned getYearsUntilLimekIsLarger(){
  unsigned count = 0;
  while(b >= a){
    count++;
    b*=2;
    a*=3;
  }

  return count;
}

int main(){
  std::cin >> a >> b;
  std::cout << getYearsUntilLimekIsLarger() << "\n";

  return 0;
}