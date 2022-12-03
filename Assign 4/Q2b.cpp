/*
Abdul Rafay
22I-8762
SE-B
*/
#include <iostream>

using namespace std;

void funn(int &radius, int &lines, bool &bott )
{
	if (!(lines>=radius))
	{
		if(bott==true)
		{
			cout<<"_";
			bott = false;
		}
		else
		{
			cout<<".";
			bott=true;
		}
		lines++;
		funn(radius,lines, bott);
	}
}

void funn(int &j, int &i)
{
	if (j<i)
	{
		cout << "*";
		j++;
		funn(j, i);
	}
}

void funn(int &j,int &radius, int &i)
{
	if (j<=(radius-2-i))
	{
		cout << "*";
		j++;
		funn(j, radius,i);
	}
}

void lower_recursion(int &i, int &radius, bool &dot, bool &bott)
{
	if (!(i>=-1+radius))
	{
		int j=0;
		funn(j,radius,i);
		dot!=dot;
		bott=dot;
		funn(radius,j,bott);
		cout<<endl;
		i++;
		lower_recursion(i,radius,dot,bott);
	}
}

int getinput()
{
	int radius;
	do 
	{
	cout<<"Enter radius: ";
	cin>>radius;
	} while (radius < 0);
	
	return radius;
}

int main()
{
	int radius;
	radius = getinput();
	bool dot = true,bott =  false;
	
	for(int i = 0; i < radius; i++)
	{
		int j=0;
		funn(j, i);
		funn(radius,j,bott);
		cout<<endl;
	}
	int i=0;
	lower_recursion(i,radius,dot,bott);

	return 0;
}