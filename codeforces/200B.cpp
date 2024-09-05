#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  int n;
  cin >> n;

  double ans = 0;

  for(int i = 0; i < n; i++) {
	int a; 
	cin >> a;

	ans += a;
  }

  cout << setprecision(5);
  cout << fixed;

  cout << ans / float(n) << "\n";

  return 0;
}
