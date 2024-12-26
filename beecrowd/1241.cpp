#include <bits/stdc++.h>

using namespace std;

void solve(string a, string b) {

	try {

		if(a.substr(a.size() - b.size()) == b) {
			cout << "encaixa\n";
		} else cout << "nao encaixa\n";

	} catch (out_of_range) {
		cout << "nao encaixa\n";
	}
}

int main() {
	int n;
	cin >> n;
	while(n--) {
		string a,b;
		cin >> a >> b;
		solve(a,b);
	}
	return 0;
}
