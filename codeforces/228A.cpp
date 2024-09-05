#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> v;

  for (int i = 0; i < 4; i++){
    int x;
    cin >> x;

    v.push_back(x);
  }

  int count = 0;

  sort(v.begin(), v.end());
  for (int i = 1; i < 4; i++) {
    if (v[i] == v[i - 1])
      count++;
  }

  cout << count << endl;

  return 0;
}
