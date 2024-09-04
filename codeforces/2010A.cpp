#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;

  while(t--) {
	int n;
	cin >> n;
	int i = 0;
	int sum = 0;

	while(n--) {
	  int a;
	  cin >> a;

	  if(i%2 == 0) {
		sum += a;
	  } else sum -= a;
	  
	  i++;
	}

	cout << sum << endl; 

  }
  return 0;
}
