#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> v;
    int x = 3;
    while (x--) {
      int a;
      cin >> a;
      v.push_back(a);
    }

    int i = 0, j = 1, k = 2;

    x = 3;
    bool found = false;
    while (x--) {
      if (v[i] == v[j] + v[k]) {
        cout << "YES\n";
        found = true;
        break;
      }
      i++;
      j++;
      k++;
      i %= 3;
      j %= 3;
      k %= 3;
    }
    if (!found)
      cout << "NO\n";
  }
  return 0;
}
