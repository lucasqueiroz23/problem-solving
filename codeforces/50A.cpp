#include <cmath>
#include <iostream>

int main() {
	int d = 2;
	int n, m;

	std::cin >> n >> m;

	std::cout << (int)floor((double)(m * n)/d)  << "\n";
	return 0;
}
