#include <iostream>   using namespace std;

void funn(int num)
{
	if (num/abs(num)==1)
	cout<<"Number is Positive!";

	if (num/abs(num)==-1)
	cout<<"Number is Negative!";

	if (num==0)
	cout<<"Number is neither Positive nor Negative!";

}
int main()
{
	float number;
	cout<<"Enter a Number to Find weather it is Positive or Negative\n";
	cin>>number;

	funn(number);
	return 0;
}

