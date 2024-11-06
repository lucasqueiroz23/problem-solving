#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

long long unsigned memo[21];

long long unsigned factorial(int n) {
	
	if(memo[n] != 0) return memo[n];
	memo[n] = n * factorial(n-1);
	return memo[n];
}

int main() {
	memo[0] = 1;

	string line;

	while (getline(cin, line)) {
		int wspos = line.find(' ');

		int a = stoi(line.substr(0, wspos));
		int b = stoi(line.substr(wspos + 1, line.length()));

		cout << factorial(a) + factorial(b) << "\n";
	}

	return 0;
}
