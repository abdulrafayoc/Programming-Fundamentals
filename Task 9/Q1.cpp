# include <iostream>

using namespace std;

int magic(int D, int M, int Y);
int main()
{
	int D, M, Y;
	cout<<"Enter Day of the magic date"<<endl;
	cin>>D;
	cout<<"Enter Month of the magic date"<<endl;
	cin>>M;
	cout<<"Enter Year of the magic date"<<endl;
	cin>>Y;
	
	MAGIC(D, M, Y);
	return 0;
}

int MAGIC(int D, int M, int Y)
{
	if (Y == D * M)
	{
		cout<<"!!THE DATE IS MAGIC!! "<<endl;
	} else {
		cout<<"THE DATE NOT IS MAGIC. "<<endl;
	}
}