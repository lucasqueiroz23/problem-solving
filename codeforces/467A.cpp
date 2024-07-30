#include <iostream>

int main() {

  int n;
  std::cin >> n;

  int ans = 0;
  while (n--) {
    int p, q;
    std::cin >> p >> q;
    if (q - p >= 2)
      ans++;
  }

  std::cout << ans << "\n";
  return 0;
}
