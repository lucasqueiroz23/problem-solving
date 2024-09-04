#include <iostream>

using namespace std;

int main() {
  int v[3] = {0, 0, 0};
  int a,b;
  cin >> a >> b;
  a--;
  b--;
  v[a] = 1;
  v[b] = 1;
  for(int i = 0; i < 3; i++) {
	if(v[i] == 0) cout << (i+1) << endl;
  }

  return 0;
}
