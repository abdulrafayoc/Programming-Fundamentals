#include <iostream>
using namespace std;

int fun(int Seconds);

int main()
{
	int Seconds;
	cout<<"Enter Seconds : "<<endl;
	cin>>Seconds;
	
	fun(Seconds);
}

int fun(int Seconds)
{
	float x;
	if(Seconds>=60 && Seconds<3600)
	{
		x=Seconds/60.0;
		cout<<x<<" Minute(s)";
	}
	else if(Seconds>=3600 && Seconds<86400)
	{
		x=Seconds/3600.0;
		cout<<x<<" Hour(s)";
	}
	else if(Seconds>=86400)
	{
		x=Seconds/86400.0;
		cout<<x<<" Day(s)";
	}
	else
	{
		cout<<Seconds<<" Second(s)";
		
	}
	return 0;
	
}