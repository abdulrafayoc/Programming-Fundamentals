#include <iostream>

using namespace std;

char bar(int S)
{
	for (int i = 0; i < S ; i++)
	{
		cout<<"*";
	}
	return ' ';
}



int main()
{
	int s1,s2,s3,s4,s5;
	cout<<"Enter today's sales for store 1 : ";
	cin>>s1;
	cout<<"Enter today's sales for store 2 : ";
	cin>>s2;
	cout<<"Enter today's sales for store 3 : ";
	cin>>s3;
	cout<<"Enter today's sales for store 4 : ";
	cin>>s4;
	cout<<"Enter today's sales for store 5 : ";
	cin>>s5;
	
	cout<<"\nStore 1 : "<<bar(s1 /= 50);
	cout<<"\nStore 1 : "<<bar(s2 /= 50);
	cout<<"\nStore 1 : "<<bar(s3 /= 50);
	cout<<"\nStore 1 : "<<bar(s4 /= 50);
	cout<<"\nStore 1 : "<<bar(s5 /= 50);
	
	
	
	
}