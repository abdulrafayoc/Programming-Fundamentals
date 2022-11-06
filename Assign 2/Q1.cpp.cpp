//Abdul Rafay 22i8762 SE-B
#include <iostream>
using namespace std;

int main()
{
  float a, b, c, d, e, f, g, h, i, j, Sum, Avg, Med;

  cout<<"Please enter 10 numbers in sorted order: "<<endl;
  cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;

  Sum=a+b+c+d+e+f+g+h+i+j;
  
  Avg=Sum/10;
  Med=(e+f)/2;
  
  cout<<"The mean of the 10 inputs is: "<<Avg<<endl;
  cout<<"The median of the 10 inputs is: "<<Med<<endl;
  
  return 0;
}