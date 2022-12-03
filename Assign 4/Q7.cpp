/*
Abdul Rafay
22I-8762
SE-B
*/
#include <iostream>

using namespace std;

void error();

float add(float n1, float n2)
{
	float n;
	for (int i = 0, n=n1; i < n2; i++)
		{
			n++;
		}
		return n;
}

float sub(float n1, float n2)
{
	float n;
	for (int i = 0, n=n1; i < n2; i++)
		{
			n--;
		}
		return n;
}

float mul(float n1, float n2)
{
	float n;
	for (int j = 0; j < n2; j++)
		{
			for (int i = 0; i < n1; i++)
			{
				n++;
			}
		}
		return n;
}

float div(float n1, float n2)
{
	float n;
	if (n2==0)
	{
		error();
		return 0;

	}
	while (n1 >= n2)
		{
			for (int i = 0; i < n2; i++)
			{
				n1--;
			}
			++n;
		}
		return n;
}

float mod(float n1, float n2)
{
	if (n1<n2)
	{
		error();
		return 0;
	}
	
		float r=0, n=0;
		while (n1 >= n2)
		{
			for (int i = 0; i < n2; i++)
			{
				n1--;
			}
			++r;
		}
		for (int j = 0; j < n2; j++)
		{
			for (int i = 0; i < r; i++)
			{
				n++;
			}
		}
		n=n1;
		return n;
	
}




int main()
{
	float n1,n2,n;
	cout<<"First Input : ";
	cin>>n1;
	cout<<"Second Input : ";
	cin>>n2;
	char op;
	cout<<"+  -  *  /  % \n";
	cout<<"Operation : ";
	cin>>op;

	switch (op)
	{
	case '+':
		n = add(n1, n2);
	break;
		
	case '-':
		n = sub(n1, n2);
	break;
	
	case '*':
		n = mul(n1, n2);
	break;
		
	case '/':
		n = div(n1, n2);
	break;
		
	case '%':
		n = mod(n1, n2);
	break;
	
	default:
		cout<<"Error\n";
		return 0;
	}
	
	cout<<"Answer : "<<n;
	
	
	
}

void error()
{
	cout<<"error\n\n";
	main();
}


