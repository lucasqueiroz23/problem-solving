#include <bits/stdc++.h>

using namespace std;

void solve(string& s) {
	for(int i = 0; i < s.size(); i++) {
		if(tolower(s[i]) >= 97 && tolower(s[i]) < 123) s[i] += 3;
	}

	for(int i = 0, j = s.size() - 1; i < j; i++, j--) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}

	for(int i = s.size() / 2; i < s.size(); i++) {
		s[i]--;
	}

	cout << s << "\n";
}

int main() {
	int n;
	cin >> n;
	cin.ignore();

	while(n--) {
		string s;
		getline(cin, s);

		solve(s);
	}
	return 0;
}
