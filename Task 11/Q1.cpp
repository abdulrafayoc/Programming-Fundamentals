#include<iostream>
using namespace std;
int merafun()
{
	for (int  i = 1 ; i <= 5 ; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i==5 || i==1)
			{
				cout << " -";
			}
			else if(i%2==0)
			{
				if (j%2==0)
				{
					cout<<" +";
				}
				else if (j%2==1)
				{
					cout<<" -";
				}
			}
			else if(i==3)
			{
				if (j%2==0)
				{
				cout<<" -";
				}
				else if (j%2==1)
				{
				cout<<" +";
				}
			}
			
		
	}
		cout << endl;
}
}

int main()
{
	merafun();
}
