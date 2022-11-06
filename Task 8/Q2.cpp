#include<iostream>
#include<cmath>

using namespace std;

float A()
{
    return (M_PI * pow(1, 2));
}

double equation(float A1)
{
    return ((A1 * 30.00) / 2000.00);
}

int main ()
{
    cout << "The value of V2 is: " << equation(A())<<" cm/s";
    return 0;
}
