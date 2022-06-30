#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int counter = 1;
	for(int i = 1;i<=n;i++)
	{
		cout << counter++ <<" ";
		cout << counter++ << " ";
		cout << counter++ << " ";

		cout << "PUM\n";
		counter++;

	}


	return 0;
}
