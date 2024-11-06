#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void solve(int n) {
  int last = -1;
  bool ok = true;

  while(n--) {
	int a;
	cin >> a;

	int check = abs(a-last);

	if (last != -1 && (check != 5 && check != 7) ) ok = false;
	last = a;
  }

  string result = ok ? "yes\n" : "no\n";

  cout << result;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
	int n;
	cin >> n;
	solve(n);
  }
  return 0;
}
