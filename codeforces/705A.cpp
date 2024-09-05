#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;

  int i = 1;


  cout << "I ";

  while(n--){

	if(i%2 == 0) cout << "love";
	else cout << "hate";

	if(n > 0) cout << " that I ";

	i++;
  }

  cout << " it\n";

  return 0;
}
