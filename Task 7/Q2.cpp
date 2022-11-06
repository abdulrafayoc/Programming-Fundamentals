#include <iostream>
#include <cmath>

using namespace std;

float vol(float rad)
{
 float vol;
 const float pi= 3.1415;

vol=(4.00/3)*pi*pow(rad,3);
	
	return vol;
}

int main()
{
float radius;
cout<<"Enter Radius";
cin>>radius;
cout<<"Radius is: "<<vol(radius);
return 0;
}