/*
Abdul Rafay
22I-8762
SE-B
*/
#include<iostream>
#include<windows.h>

using namespace std;

void top(int &num , int &line)
{
	for(int i=2; i<=num; i++)
	{
		line=2;
		while (line<=(2*num)-2)
		{
			if((line>=num-(i-1)) && (line<=num+(i-1)))
			{
				cout<<"*";
			}
			else
			{
				cout<<".";
			}
		    line++;
		}
		cout<<endl;
	}	
}
	
void bottom(int &num , int &line)
{
	for(int i=2; i<num; i++)
	{
		line=2;
		while (line<i)
		{
			cout<<".";
			line++;
		}
		line=i;
		while (line<=num)
		{
			cout<<"*";
			line++;
		}
		line=i;
		while (line<num)
		{
			cout<<"*";
			line++;
		}
		line=3; 
		while (line<=i)
		{
			cout<<".";
			line++;
		}
		cout<<endl;
	}
}
int main()
{
	int num;
	int line;
	cout<<"For diameter = ";
	do 
	{
		cin>>num;
	} while (num<0);
	num-=3;

	system("cls");
	top(num,line);
	bottom(num,line);

	return 0;
}

