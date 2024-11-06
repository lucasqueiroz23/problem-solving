#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int> m;

void solve() {
  int n, k;
  cin >> n >> k;

  int sum = 0;
  int it = k;

  
  while(it--) {
    int b, c;
    cin >> b >> c;
    m[b] += c;
  }

  vector<int> v;

  for(auto it = m.begin(); it != m.end(); it++) 
    v.push_back(it->second);

  sort(v.begin(), v.end(), greater<int>());

  for(int i = 0; i < n && i < v.size(); i++) sum += v[i];
  cout << sum << "\n";

  m.clear();

}

int main() {
  int t;
  cin >> t;
  while(t--) {
	solve();
  }
  return 0;
}
