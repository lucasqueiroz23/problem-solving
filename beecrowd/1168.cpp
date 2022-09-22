#include <iostream>
#include <string>

int main() {

    int ar[10] = {6,2,5,5,4,5,6,3,7,6};
	int n = 0;

	std::cin >> n;

	while(n>0){
		std::string led = "";
		std::cin >> led;
		int sum = 0;
		for(int i = 0; i< led.length(); i++){
			int num = (int) led[i] - 48;
			sum+=ar[num];
		}
		std:: cout << sum <<" leds\n";
		n--;
	}

    return 0;
}
