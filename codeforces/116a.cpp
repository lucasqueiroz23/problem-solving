#include <iostream>

int main(){
  int n = 0;
  std::cin >> n;
  int capacity = 0, max = 0;
  while(n--){
    int a = 0;
    int b = 0;
    std::cin >> a >> b;
    capacity += b - a;
    if(capacity > max)
      max = capacity;
  }
  std::cout << max << "\n";
  return 0;
}