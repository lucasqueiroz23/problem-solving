#include <iostream>

int main()
{
	int counter = 0;
	for(int i = 0;i<6;i++)
	{
		float val = 0;
		std::cin >> val;
		if(val>0) counter++;

	}

	std::cout << counter << " valores positivos\n";

	return 0;
}
