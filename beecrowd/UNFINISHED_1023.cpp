#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef struct casa
{
	int x,y;
	int z;

}casa ;

bool aux(casa a, casa b)
{
	if(a.z < b.z)
		return 1;
	else
		return 0;

}

int main()
{
	int n = 10 ,i=1;
	cin >> n;
	while(n!=0)
	{

		casa ar[n];
		for(int j = 0;j<n;j++)
		{
			cin >> ar[j].x >> ar[j].y;
			ar[j].z = ar[j].y/ar[j].x;

		}
		sort(ar,ar+n-1,aux);
		cout << "Cidade# "<<i<<":\n";
		for(int j = 0;j<n;j++)
		{
			cout << ar[j].x << "-"<<ar[j].z <<" ";
		}
		cout << "\nConsumo medio: ";
		float c=0,x=0;
		for(int k = 0;k<n;k++)
		{
			c += float(ar[k].y);
			x += float(ar[k].x);
		}
		c/=x;
		cout << fixed << setprecision(2) << c<< " m3.";



		cout <<"\n";
		i++;
		cin >>n;
		if(n!=0) cout <<"\n";
	}

	return 0;
}
