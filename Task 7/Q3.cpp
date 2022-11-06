#include <iostream>

using namespace std;

int sad(int P,int Br,int Dr ,int Y)
{
	return (Y*(P+Br-Dr));
}

int main()
{
	float N ,P ,Br ,Dr ,Y , B, D ;
	cout<<"Enter Inital Population ";
	cin>>P;
	cout<<"Enter Birth Rate ";
	cin>>Br;
	cout<<"Enter Death Rate ";
	cin>>Dr;
	cout<<"Enter Years ";
	cin>>Y;
	B=(Br/100)*P;
	D=(Dr/100)*P;
	cout<<sad(P,B,D,Y);
	
	return 0;
}