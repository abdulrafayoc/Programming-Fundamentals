//Abdul Rafay 22i8762 SE-B
#include <iostream>
using namespace std;

int main()
{
	float pay, rate, hours;
	
	cout<<"Input rate per hour: ";
	cin>>rate;	
	cout<<"Input Hours of the salesman: ";
	cin>>hours;	
	
	pay=(rate*40)+((1.5*rate)*(hours-40));
	
	cout<<"The Result is: "<<pay;

  return 0;
}