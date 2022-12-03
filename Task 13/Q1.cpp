#include<iostream>

using namespace std;

int main()
{
	int mtrx[3][3];
	int sum =0;

	for(int i=0; i<3; ++i)
	{
		for(int j=0; j<3; ++j)
		{
			cout<<"Enter Element in Matrix in row "<<i+1<<" and column "<<j+1<<" = ";
			cin>>mtrx[i][j];
		}
	}
	
	for(int i=0; i<3; ++i)
	{
		for(int j=0; j<3; ++j)
		{
			if ((i == 1 && j == 0) || (i == 2 && (j == 0 || j == 1 )))
			sum += mtrx[i][j];
		}
	}
	
	cout<<"Sum is "<<sum<<" !";
	return 0;
}