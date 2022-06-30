#include <iostream>

using namespace std;

int main()
{
	int q = 0;
	cin >> q;
	while(q>0)
	{
		int n1=0,n2=0,d1=0,d2=0;
		char div,op;
		cin >> n1 >> div >> d1 >> op >> n2 >> div >> d2;

		int num=0,den=0;

		switch(op)
		{
			case '-':
				num = n1*d2 - n2*d1;
				den = d1*d2;
				break;
			case '+':
				num = n1*d2 + n2*d1;
				den = d1*d2;
				break;
			case '*':
				num = n1*n2;
				den = d1*d2;
				break;
			case '/':
				num = n1*d2;
				den = n2*d1;
				break;
		}
		cout << num << div << den<<" = ";

		int maior = 0;
		if(num > den)
			maior = num;
		else
			maior = den;

		for(int i = maior;i>=2;i--)
		{
			if(num%i == 0 && den%i == 0)
			{
				num/=i;
				den/=i;
				//cout<<"OI";
			}

		}

		cout << num << div << den << "\n";

		q--;
	}

	return 0;
}
