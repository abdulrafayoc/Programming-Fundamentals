#include <iostream>

using namespace std;

float sum(float a, float b)
{
 return (a + b);
}


float dif(float a, float b)
{
 return (a - b);
}


float mul(float a, float b)
{
 return (a * b);
}


float divi(float a, float b)
{
 return (a / b);
}


int main()
{
    float  a , b;
    cout << "Entre Two Numbers"<<endl;
    cin>>a>>b;
    cout << " the Sum of two numbers is: "<< sum(a , b) <<endl;
    cout << " the Differance of two numbers is: "<< dif(a , b) <<endl;
    cout << " the Product of two numbers is: "<< mul(a , b) <<endl;
    cout << " the Division of two numbers is: "<< divi(a , b) <<endl;
    return 0;
}