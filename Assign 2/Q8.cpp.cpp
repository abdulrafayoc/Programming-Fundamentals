//Abdul Rafay 22i8762 SE-B
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float A, B;

        cout<<"Enter First Number"<<endl;
        cin>>A;
        cout<<"Enter Second Number"<<endl;
        cin>>B;

        A=A+B;
        B=A-B;
        A=A-B;

        cout<<"Now, First Number is "<<A<<" and Second Number is "<<B<<endl;



	return 0;
}