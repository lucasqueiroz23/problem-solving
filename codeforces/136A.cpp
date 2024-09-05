#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> v(n);
  int len = v.size();

  for (int i = 0; i < len; i++) {
    int p;
    std::cin >> p;
    v[p - 1] = i + 1;
  }

  for (auto f : v)
    std::cout << f << " ";

  std::cout << "\n";

  return 0;
}
