#include <bits/stdc++.h>

using namespace std; 

int main() {
  int n,k;

  cin >> n >> k;

  int count = 0;
  int i = 1;

  while(i <= n && k < 4 * 60) {
    if(k + i*5 > 4 * 60) break;

    k += i*5;
    count++;
    i++;
  }

  cout << count << endl;

  return 0;
}
