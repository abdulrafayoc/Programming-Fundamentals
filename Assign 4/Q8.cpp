/*
Abdul Rafay
22I-8762
SE-B
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int n, no=0;
	cout<<"Enter a range for all sides : ";
	cin>>n;
	float  t = 0;

	cout<<"Side-a"<<setw(10)<<"Side-b"<<setw(15)<<"Hypotenous"<<endl;
	cout<<"........................................"<<endl;
	for (int i = 1 ;  i <= n ; i++)
	{
		for (int j = 1; j <= n ; j++)
		{
			t= sqrt (pow(i,2) + pow(j,2));
			if (floor(t)==t)
			{
			cout<<i<<setw(10)<<j<<setw(15)<<t<<endl;
			no++;
			}
		}
	}
cout<<"A total of "<<no<<" Pythagorean Triples were found in range "<<n;
return 0;
}
