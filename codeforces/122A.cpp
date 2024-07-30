#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int options[] = {4,   44,  444, 7,  77,  777, 47,
                   477, 447, 474, 74, 744, 774, 747};
  for (int opt : options) {
    if (n % opt == 0) {
      std::cout << "YES\n";
      return 0;
    }
  }

  std::cout << "NO\n";

  return 0;
}
