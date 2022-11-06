#include <iostream>
#include <cmath>

using namespace std;

int main()
{
float p1_p2, velocity1=160;
float density=1.2900, x, velocity;
x=(2*(p1_p2+(density*velocity1*velocity1)/2)/density);

velocity=sqrt(x);

cout<<"Second Velocity:"<<velocity<<"meter per sec";


    return 0;
}