#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a,b,c;

	cin >> a;
	cin >> b;
	cin >> c;

	if(a == "vertebrado")
	{
		if(b == "ave")
		{

			if(c == "carnivoro")
				cout << "aguia\n";
			if(c == "onivoro")
				cout << "pomba\n";

		}
		if(b == "mamifero")
		{
			if(c == "onivoro")
				cout << "homem\n";
			if(c == "herbivoro")
				cout << "vaca\n";
		}
	}

	if(a == "invertebrado")
	{
		if(b == "inseto")
		{

			if(c == "hematofago")
				cout << "pulga\n";
			if(c == "herbivoro")
				cout << "lagarta\n";

		}
		if(b == "anelideo")
		{
			if(c == "hematofago")
				cout << "sanguessuga\n";
			if(c == "onivoro")
				cout << "minhoca\n";
		}
	}

	return 0;
}
