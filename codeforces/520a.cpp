#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  map<char, bool> m;
  int len = s.size();

  for (int i = 0; i < len; i++) {
    m[tolower(s[i])] = true;
  }

  if (m.size() != 26)
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}
