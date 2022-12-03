/*
Abdul Rafay
22I-8762
SE-B
*/
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int n,h,w,g;
    cout<<"Enter Steps : ";
    cin>>n;
    cout<<"Enter Height : ";
    cin>>h;
	cout<<"Enter Width : ";
    cin>>w;
	    char c='*';
    int a=char(c);
    while (1)
{
     sleep(1);   	
     system("cls");   	
	 g = (n*w);    	
    for (int i = 0; i < n ; i++)
    {
     a+=1;
        for (int k = 0; k <= h ; k++)
        {
        	cout<<setw(g);
        	if (k==0)
        	{
        	    for (int j = w ; j > 0 ; j--)
        	    {
        	    	cout<<char(a);
			    }
			    cout<<setw((n*w)-g+1)<<char(a);
			}
			else
			{
        	    cout<<char(a)<<setw((n*w)-g+w)<<char(a);
			}
			cout<<"\n";
		}
		g-=w;
		if(a>=40+n)
		{
			a=41;
		}
    }
    for (int k = 0; k < (n*w)+w; k++)
    {
        cout<<"*";
    }
}


    return 0;
}