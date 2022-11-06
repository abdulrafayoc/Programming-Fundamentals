#include <iostream>
using namespace std;

int angle(int A1, int A2)
{

	return 180-A1-A2;
}

int main()
{
int A1, A2;
cout<<"Enter Two Angles";
cin>>A1>>A2;
cout<<"the Third Angle is: "<<angle(A1,A2);

return 0;
}