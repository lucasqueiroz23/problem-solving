#include <iostream>
#include <string>

int main() {
    std::string in;
    std::cin >> in;

    for(auto c: in) {
	if(c == 'H' || c == 'Q' || c == '9') {
	  std::cout << "YES\n";
	  return 0;
	}
    }

    std::cout << "NO\n";
    return 0;
}
