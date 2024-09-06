#include <bits/stdc++.h>
#include <cmath>

using namespace std;

void solve(int n) {
  int pot = 0;
  vector<int> p;

  while(n>0) {
	int x = n % 10;
	if(x != 0) {
	  p.push_back(x * (int)pow(10, pot));
	}

	n/=10;
	pot++;
  }

  cout << p.size() << "\n";

  for(auto x : p) cout << x << " ";

  cout << endl;
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
