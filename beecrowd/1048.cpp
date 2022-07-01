#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float s = 0;
	cin >> s;

	cout << fixed << setprecision(2);

	if(s >= 0 && s <= 400)
	{
		float r1 = 0.15;
		float r2 = r1*s;
		s+=r2;

		cout << "Novo salario: " << s << "\n";
		cout << "Reajuste ganho: " << r2 << "\n";
		cout << "Em percentual: " << int(r1*100) << " %\n";
		return 0;
	}

	if(s >= 400.01 && s <= 800)
	{
		float r1 = 0.12;
		float r2 = r1*s;
		s+=r2;

		cout << "Novo salario: " << s << "\n";
		cout << "Reajuste ganho: " << r2 << "\n";
		cout << "Em percentual: " << int(r1*100) << " %\n";
		return 0;
	}

	if(s >= 800.01 && s <= 1200)
	{
		float r1 = 0.1;
		float r2 = r1*s;
		s+=r2;

		cout << "Novo salario: " << s << "\n";
		cout << "Reajuste ganho: " << r2 << "\n";
		cout << "Em percentual: " << int(r1*100) << " %\n";
		return 0;
	}

	if(s >= 1200.01 && s <= 2000)
	{
		float r1 = 0.07;
		float r2 = r1*s;
		s+=r2;

		cout << "Novo salario: " << s << "\n";
		cout << "Reajuste ganho: " << r2 << "\n";
		cout << "Em percentual: " << int(r1*100) << " %\n";
		return 0;
	}

	if(s >2000)
	{
		float r1 = 0.04;
		float r2 = r1*s;
		s+=r2;

		cout << "Novo salario: " << s << "\n";
		cout << "Reajuste ganho: " << r2 << "\n";
		cout << "Em percentual: " << int(r1*100) << " %\n";
		return 0;
	}


}
