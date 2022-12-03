/*
Abdul Rafay
22I-8762
SE-B
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
    int n1,n2,n3,n4,n5;
	cout<<"input = ";
    cin>>n1;
	cout<<"input = ";
    cin>>n2;
	cout<<"input = ";
    cin>>n3;
	cout<<"input = ";
    cin>>n4;
	cout<<"input = ";
    cin>>n5;
    
    system("cls");

    for (int i = max(n1,max(n2,max(n3,max(n4,n5))))+2; i >= 1; i--)
    {
        cout<<setw(2)<<	setfill('0')<<i<<"\t";
        if (n1 >= i)
        {
            cout<<"*";
        }
        cout<<"\t";

        if (n2 >= i)
        {
            cout<<"*";
        }
        cout<<"\t";

        if (n3 >= i)
        {
            cout<<"*";
        }
        cout<<"\t";

        if (n4 >= i)
        {
            cout<<"*";
        }
        cout<<"\t";

        if (n5 >= i)
        {
            cout<<"*";
        }
        cout<<"\t";
        cout<<endl;
    }

    cout<<"\t1\t2\t3\t4\t5\n";
    cout<<"\t("<<n1<<")\t("<<n2<<")\t("<<n3<<")\t("<<n4<<")\t("<<n5<<")";
}