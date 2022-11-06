#include<iostream>
using namespace std;
int merafunck()
{
	int c;
	cin >> c;
	int a=0;
	while (c>=1)
	{
		a+=c%2;
		c/=2;
	}
	return a;
}

int main()
{
	cout<<merafunck();
}
