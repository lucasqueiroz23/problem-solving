#include <iostream>

int main() {
	int n = 0;
	std::cin >> n; 
	int arr[] = { 1, 5, 10, 20, 100 };
	int count = 0;

	for(int i = 4; i >= 0; i--) {
		while(n >= arr[i]) {
			n -= arr[i];
			count++;
		}
	}

	std::cout << count <<"\n";
	return 0;
}
