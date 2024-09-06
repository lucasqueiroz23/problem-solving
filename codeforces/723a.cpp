#include <bits/stdc++.h>

using namespace std;

int main() {
  int ans = 0;
  vector<int> v;

  for (int i = 0; i < 3; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());

  int m = (v[0] + v[2]) / 2;

  for (int i = 0; i < 3; i += 2) {
    ans += abs(v[i] - m);
  }

  cout << ans << endl;

  return 0;
}
