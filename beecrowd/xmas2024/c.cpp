#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	map<string, int> months{
        {"january", 31},
        {"february", 28},
        {"march", 31},
        {"april", 30},
        {"may", 31},
        {"june", 30},
        {"july", 31},
        {"august", 31},
        {"september", 30},
        {"october", 31},
        {"november", 30},
        {"december", 31}
    };

	int ans = 0;

	while(n--) {
		string input;
		int x;
		cin >> input >> x;

		ans += months[input] * x;
	}

	cout << ans << "\n";
	return 0;
}
