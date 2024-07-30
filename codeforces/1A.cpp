#include <iostream>
#include <cmath>

int main() {
	int n, m, a;
	std::cin >> n >> m >> a;

	std::cout << (long long int)(ceil((double)n/a) * ceil((double)m/a)) << "\n";
	return 0;
}
