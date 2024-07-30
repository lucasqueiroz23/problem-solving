#include <cmath>
#include <iostream>

int main() {
	int d = 2;
	int n, m;

	std::cin >> n >> m;

	std::cout << (int)floor((double)(m * n)/2)  << "\n";
	return 0;
}
