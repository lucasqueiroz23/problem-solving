#include <bits/stdc++.h>

using namespace std;

int main() {

  string s1, s2;
  cin >> s1 >> s2;

  int len = s1.size();

  for (int i = 0; i < len; i++) {
    if (s1[i] != s2[i])
      cout << "1";
    else
      cout << "0";
  }

  cout << "\n";
  return 0;
}
