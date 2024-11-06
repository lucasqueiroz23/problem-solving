#include <iostream>
#include <vector>

using namespace std;

int main() {

	while(true) {
		int n;
		cin >> n;
		if(n == 0) break;

		vector<int> discarded;
		vector<int> cards;

		for(int i = 0; i < n; ++i)
			cards.push_back(i);

		while(cards.size() >= 2) {
			discarded.push_back(cards[0]);
			cards.erase(cards.begin());
			cards.push_back(cards[0]);
			cards.erase(cards.begin());
		}

		cout << "Discarded cards: ";
		for(int i = 0; i < discarded.size(); ++i) {
			cout << discarded[i] + 1;
			if(i < discarded.size() - 1) cout << ", ";
		}
		cout << "\n";

		cout << "Remaining card: " << cards[0] + 1 << "\n";



	}

	return 0;
}
