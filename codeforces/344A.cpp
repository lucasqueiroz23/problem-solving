#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int last = 0;
  int ans = 0;
  while (n--) {
    int x;
    std::cin >> x;

    if (x != last)
      ans++;

    last = x;
  }
  std::cout << ans << "\n";
  return 0;
}
