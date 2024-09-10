#include <bits/stdc++.h>

using namespace std;

int main() { 

  int n;
  cin >> n;
  vector<int> v;
  int b = 0;

  while(n--) {
	int x;
	cin >> x;
	b += x;
	v.push_back(x);
  }

  sort(v.begin(), v.end());
  int count = 0;
  int e = 0;

  int pos = v.size() - 1;

  while(e <= b) {
	e += v[pos];
	b -= v[pos];

	count++;
	pos--;
  }

  cout << count << "\n";

  return 0;
}
