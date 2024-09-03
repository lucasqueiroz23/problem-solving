#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  cin >> n;
  long long ans = 0;
  bool even = n % 2 == 0;

  if(!even) n++;

  ans = even ? n/2 : -n/2;


  cout << ans << "\n";

  return 0;
}
