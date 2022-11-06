#include<iostream>
using namespace std;
int main()
{
	int a=0;
	for (int  i = 1 ; i <= 7 ; i++)
	{
		for (int j = 7; j>i ; j--)
		{
			cout << "*";
		}
		
		for (int l = i; l>=0 ; l--)
		{
			cout << " ";
		}
		
		for (int k = 12; k>a; k--)
		{
			cout << "/";
		}
		
		for (int k = a+1; k>0; k--)
		{
			cout << "\\";
		}
		
		for (int l = i; l>=0 ; l--)
		{
			cout << " ";
		}
		for (int k = 7; k>i; k--)
		{
			cout << "*";
		}
		
		
		a+=2;
		
		cout << endl;
	}
}

