#include <iostream>

int main(){
  int n;
  std::cin >> n;
  int sum = 0;
  while(n--){
    int t = 0, v = 0;
    std::cin >> t >> v;
    sum += t*v;
  }

  std::cout << sum << "\n";
  return 0;
}