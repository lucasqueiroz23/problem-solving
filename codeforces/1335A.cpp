#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::cout << (n - 1) / 2 << std::endl;
  }
  return 0;
}
