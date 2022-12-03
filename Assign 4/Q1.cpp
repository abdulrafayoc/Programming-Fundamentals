/*
Abdul Rafay
22I-8762
SE-B
*/

#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
int main()
{
	int s=0, m=0, h=0;
	while (1==1)
	{
		system("cls");
		cout<<"HH : MM : SS\n";
		cout<<setw(2)<<setfill('0')<<h<<" : "
			<<setw(2)<<setfill('0')<<m<<" : "
			<<setw(2)<<setfill('0')<<s;
		sleep(10);
		s+=10;
		if (s>=60)
		{
			s=0;
			m++;	
		}
		if (m>=60)
		{
			m=0;
			h++;	
		}
		if (h>=24)
		{
			h=0;
		}
	}
}