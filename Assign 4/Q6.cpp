/*
Abdul Rafay
22I-8762
SE-B
*/
#include <iostream>

using namespace std;
void fun(int &x, int &n, int &y , int &nwnm , int &j);
int func(int &y, int &n, int x , int nwnm , int j );

int main()
{

    int number = 1, nwnm;
    cout<<"Enter number : ";
    cin>>number;
    int  j, count, temp;

    for (int x= 0 ;x <= 7 ; x++)
    {
        func(temp, number, count , nwnm , j);
    }
    return 0;
}
int func(int &y, int &n, int x , int nwnm , int j )
{
	nwnm =  0;
        j = 1;

        cout<<n<<endl;

        while (n)
        {
            fun(y, n, x , nwnm , j);
        }

        n = nwnm;
        
        return 0;
}
void fun(int &x, int &n, int &y , int &nwnm , int &j )
{
    x = n % 10;
    n /=10;
    y = 1;
    while (x == (n%10))
    {
        y++;
        n /=10;
    }
    nwnm += (((10*y) + x) *j);
    j *= 100;
    
}