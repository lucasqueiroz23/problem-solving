#include <iostream>

int main()
{
	int ddd;
	std::cin >> ddd;

	switch(ddd)
	{
		case 61:
			std::cout << "Brasilia\n";
			break;
		case 71:
			std::cout << "Salvador\n";
			break;
		case 11:
			std::cout << "Sao Paulo\n";
			break;
		case 21:
			std::cout << "Rio de Janeiro\n";
			break;
		case 32:
			std::cout << "Juiz de Fora\n";
			break;
		case 19:
			std::cout << "Campinas\n";
			break;
		case 27:
			std::cout << "Vitoria\n";
			break;
		case 31:
			std::cout << "Belo Horizonte\n";
			break;
		default:
			std::cout << "DDD nao cadastrado\n";
			break;
	}

	return 0;
}
