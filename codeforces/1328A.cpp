#include <bits/stdc++.h>

using namespace std;

void solve(unsigned int a, unsigned int b) {

  int ans = 0;

  int r = a % b;
  int q = a / b;

  ans = (b - r) % b;

  cout << ans << endl;

}

int main() {
  int t;
  cin >> t;

  while(t--) {
	unsigned int a, b;
	cin >> a >> b;
	solve(a,b);
  }

  return 0;
}
