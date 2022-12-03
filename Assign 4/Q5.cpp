/*
Abdul Rafay
22I-8762
SE-B
*/
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cmath>
using namespace std;
int main()
{
    int n,x;
    cout<<"Input 'n' = ";
    cin>>n;
	cout<<"Input 'x' = ";
	cin>>x;
    system("cls");
    for (int i = x*5; i >= 0; i--)
    {
        cout<<setw(2)<<	setfill('0')<<i<<"\t";

        for (int z = x * -1 ; z <= x ; z++)
        {
            int y=(pow(z,n)-pow(z,(n-1)));
            if (y==i)
            {
                cout<<"*";
            }
            cout<<"\t";
        }
        cout<<endl;
    }
    for (int z = -1 * x ; z <= x ; z++)
    {
    cout<<"\t"<<z;
	}
}
