/*
Abdul Rafay
22i-8762
SE-B
*/
#include <iostream>

using namespace std;

//linent functions
int linient(int A, int B, int C)
{
    if (A < B || B < C)
    {
        cout<<"Increasing!";
    }
    else if (A == B && B == C )
    {
        cout<<"Both Increaasing and Decreasing!";
    }
    else if (A > B || B > C)
    {
        cout<<"Decreasing!";
    }
    return 0;
    
}
    //strict functions

int strict(int A, int B, int C)
{
    if (A < B && B < C)
    {
        cout<<"Increasing!";
    }
    else if (A > B && B > C)
    {
        cout<<"Decreasing!";
    }
    else
    {
        cout<<"Neither";
    }
    return 0;
}

int main()
{
	bool mode;
	int num1, num2, num3;
	//getting inputs
	cout<<"Strict mode [1] or Linient [0]";
    cin>>mode;
    cout<<"Enter First Number";
    cin>>num1;
    cout<<"Enter Second Number";
    cin>>num2;
    cout<<"Enter Third Number";
    cin>>num3;
    (mode == 1)    ?	(strict(num1, num2, num3))    :    (linient(num1, num2, num3));
    
    return 0;
}


