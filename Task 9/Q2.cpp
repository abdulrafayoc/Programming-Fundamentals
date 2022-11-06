#include <iostream>

using namespace std;

int BANK(string type, double balance);

int main()
{
	double balance;
	string type;
	
	cout<<"Enter your Account Type: "<<endl;
	cin>>type;
	cout<<"Enter your Account Balance: "<<endl;
	cin>>balance;
	
	cout<<"Updated Balance is: "<<BANK(type,balance)<<endl;
	
	return 0;
}

int BANK(string type, double balance)
{
	if (type =="Savings")
	{
		if(balance<200)
		{
			balance-=10;
		}else
		{	
			balance+=balance*0.04;
		}
	}
	else if ("Checking")
	{
		if(balance<200)
		{
			balance-=25;
		}
		else
		{
			if(balance>5200)
			{
			balance+=balance*0.03;
			}
			else
			{
			balance+=balance*0.05;
			}
		}
	}
		return balance;
}