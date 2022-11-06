//Abdul Rafay 22i8762 SE-B
#include <iostream>
using namespace std;

int main()
{

    float S, U, T, A;
cout<<"Enter Distance traveled in time t:"<<endl;
cin>>S;
cout<<"Enter Initial Velocity:"<<endl;
cin>>U;
cout<<"Enter time taken by the body:"<<endl;
cin>>T;
cout<<"Enter Acceleration of body:"<<endl;
cin>>A;

S=(U*T)+(0.5*A*T*T);

    cout<<"Distance covered by the body is "<<S;

    return 0;
}