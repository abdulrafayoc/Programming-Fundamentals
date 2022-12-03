#include<iostream>
#include<windows.h>

using namespace std;

bool check(char mtrx[][3], char t)
{
	if((mtrx[0][0]==t && mtrx[0][1]==t && mtrx[0][2]==t)||(mtrx[1][0]==t && mtrx[1][1]==t && mtrx[1][2]==t)||(mtrx[2][0]==t && mtrx[2][1]==t && mtrx[2][2]==t)||(mtrx[2][0]==t && mtrx[2][1]==t && mtrx[2][2]==t) || (mtrx[0][0]==t && mtrx[1][1]==t && mtrx[2][2]==t) || (mtrx[0][2]==t && mtrx[1][1]==t && mtrx[2][0]==t))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	char mtrx[3][3] = {{'*','*','*'},{'*','*','*'},{'*','*','*'}};
	int row, col;
	while (1)
	{
		system("cls");
		//PLAYER 1
		for(int i=0; i<3; ++i)
		{
			for(int j=0; j<3; ++j)
			{
				cout<<mtrx[i][j]<<" ";
			}
			cout<<endl;
		}

		cout<<"X---X--- Player 1 ---X---X";
		cout<<"Enter Row = ";
		cin>>row;
		cout<<"Enter Column = ";
		cin>>col;
		mtrx[row][col] = 'X';
		if (check(mtrx, 'X'))
		{
			cout<<"\n-------------------------------\n"
			    <<"X---X--- Player 1 Wins ---X---X"
			    <<"\n-------------------------------\n";
			break;
		}			//PLAYER 2
		system("cls");

		for(int i=0; i<3; ++i)
		{
			for(int j=0; j<3; ++j)
			{
				cout<<mtrx[i][j]<<" ";
			}
			cout<<endl;
		}

		cout<<"X---X--- Player 2 ---X---X\n";
		cout<<"Enter Row = ";
		cin>>row;
		cout<<"Enter Column = ";
		cin>>col;
		mtrx[row][col] = 'O';
		if (check(mtrx, 'O'))
		{
			cout<<"\n-------------------------------\n"
			    <<"O---O--- Player 2 Wins ---O---O"
			    <<"\n-------------------------------\n";
			break;
		}
	}
	return 0;
}