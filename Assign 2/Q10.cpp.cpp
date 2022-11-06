//Abdul Rafay 22i8762 SE-B
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	 double SinX=0 , CosX=0 , Angle=0;

        cout<<"Enter Angle in Degrees"<<endl;
        cin>>Angle;

		Angle=(Angle*3.141592653589793238433832795)/180;
        SinX=Angle-(pow(Angle,3)/6)+(pow(Angle,5)/120)-(pow(Angle,7)/5040)+(pow(Angle,9)/362880);
        CosX=1-(pow(Angle,2)/2)+(pow(Angle,4)/24)-(pow(Angle,6)/720)+(pow(Angle,8)/40320);

        cout<<"sin(x) is equal to "<<SinX<<"\ncos(x) is equal to "<<CosX<<endl;

	return 0;
}