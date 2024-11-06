#include <iostream>
#include <numeric>

using namespace std;

int main() {
	int n;
	cin >> n;
	while(n--) {
		int a, b;
		cin >> a >> b;
		cout << gcd(a, b) << "\n";
	}
	return 0;
}
