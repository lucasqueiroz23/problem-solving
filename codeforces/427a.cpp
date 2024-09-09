#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int count = 0;
  int cops = 0;
  while(n--) {
	int x = 0;
	std::cin >> x;
	if(x == -1) {
	  if(cops > 0) cops--;
	  else count++;
	} else cops += x;
  }

  std::cout << count << std::endl;
  return 0;
}
