#include<iostream>

using namespace std;

verify_order(int n1,int n2)
{
	if(n1!=n2)
	{
		cout<<"---------------------------"
		    <<"!Couldn\'t Multiply Matrix!"
		    <<"---------------------------";
	}
}

int main()
{
	int R1,C1,R2,C2;
	int mtrx1[10][10],mtrx2[10][10],Result[10][10]= {0};

	cout<<"Enter Number of Rows of First Matrix = ";
	cin>>R1;
	cout<<"Enter Number of Columns of First Matrix = ";
	cin>>C1;
	cout<<"Enter Number of Rows of Second Matrix = ";
	cin>>R2;
	cout<<"Enter Number of Columns of Second Matrix = ";
	cin>>C2;

	verify_order(C1,R2);


	for(int i=0; i<R1; i++)
	{
		for(int j=0; j<C1; j++)
		{
			cout<<"Enter Element in First Matrix in row "<<i+1<<" and column "<<j+1<<" = ";
			cin>>mtrx1[i][j];
		}
	}
	cout<<"\n------------------------------------------------------------------\n";
	for(int i=0; i<R2; i++)
	{
		for(int j=0; j<C2; j++)
		{
			cout<<"Enter Element in Second Matrix in row "<<i+1<<" and column "<<j+1<<" = ";
			cin>>mtrx2[i][j];
		}
	}

	for(int i=0; i<R1; i++)
	{
		for(int j=0; j<C2; j++)
		{
			for(int k=0; k<C1; k++)
			{
				Result[i][j]+=mtrx1[i][k]*mtrx2[k][j];
			}
		}
	}

	

	for(int i=0; i<R1; ++i)
	{
		for(int j=0; j<C2; ++j)
		{
			cout<<Result[i][j]<<"\t";
		}
		cout<<endl;
	}
	return 0;
}
