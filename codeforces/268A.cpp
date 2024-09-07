#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> teams;
  while(n--) {
	int a, b;
	cin >> a >> b;
	teams.push_back({a, b});
  }

  int count = 0;

  for(int i = 0; i < teams.size(); i++) {
	for(int j = 0; j < teams.size(); j++) {
	  if (i == j) continue;
	  if(teams[i].first == teams[j].second)
		count++;
	}
  }

  cout << count << endl;

  return 0;
}
