//Abdul Rafay 22i8762 SE-B
#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    float Pin, Amnt, Rt, Nm=12 , Tm;
    
    cout<<"Enter Principal amount deposited in account:"<<endl;
    cin>>Pin;

    cout<<"Enter Annual interest rate in Percentage:"<<endl;
    cin>>Rt;
    
    Rt=Rt*0.01;
    
    cout<<"Enter Investment tenure in the years:"<<endl;
    cin>>Tm;

    Amnt=Pin*(pow((1+(Rt/Nm)),(Nm*Tm)));

    cout<<"Your Compounded Interest is "<<Amnt;
    return 0;
}