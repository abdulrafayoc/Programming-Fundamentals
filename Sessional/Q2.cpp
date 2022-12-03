#include <iostream>
#include <iomanip>

using namespace std;

void funn(int n)
{
	for (int i=0 ; i<n ; i++)
	{
		if (i==0)		
		cout<<setw(n-i+1)<<"*"<<endl;
		else
		cout<<setw(n-i+1)<<"*"<<setw(2*i)<<"*"<<endl;
	}
	
	for (int i=0 ; i<n ; i++)
	{	
		cout<<"*"<<setw(2*(n))<<"*"<<endl;
	}

	for (int i=n ; i>=0 ; i--)
	{
		if (i>0)		
		cout<<setw(n-i+1)<<"*"<<setw(2*i)<<"*"<<endl;
		if (i==1)
		cout<<setw(n-i+2)<<"*"<<endl;
	}
}
int main()
{
	int n;
	do
	{
	cout<<"Enter a Number\n";
	cin>>n;
	} while (n>0);
	funn(n);
	return 0;
}


