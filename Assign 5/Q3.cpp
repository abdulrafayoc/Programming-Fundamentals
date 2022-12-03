#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

void show(char arr[][20]);

int attack(char area[][20], char hidd[][20])
{
	system("cls");
	show(hidd);
	cout<<"\n\n\n\t!!!! Attack Battleships !!!!\n";
	cout<<"\n\tEnter location on which Missile is gonna Hit \n   \tRow Number and Columns Number [R C] : ";
	int row, col;
	cin>>row>>col;

	if (area[row][col] == 'A')
	{
		hidd[row][col] = 'X';
		area[row][col] = 'X';
		cout<<"\n\t!!!HIT!!!\n";

		return 1;
	}
	else
	{
		cout<<"\n\t!!!miss!!!\n";
		return 0;
	}

	sleep(5);
}

void show(char arr[][20])
{
	system("cls");
	for(int i=0; i<20; i++)
	{
		cout<<endl;
		cout<<setw(2)<<setfill('0')<<i<<"  ";

		for(int j=0; j<20; ++j)
		{
			if (i==0)
			{
				cout<<setw(2)<<setfill('0')<<j<<"  ";
			}
			else
			{

				cout<<arr[i][j]<<"   ";
			}
		}
	}
}



void input(char area[][20])
{
	cout<<"\n\n\n\t!!!!Let\'s Place Battleships in our locations!!!!\n";
	cout<<"\tEnter Orientation of your battleships \n   \tHorizantal[h] or Vertical[v] : ";
	char orr;
	cin>>orr;
	cout<<"\n\tEnter location of your battleships \n   \tRow Number and Columns Number [R C] : ";
	int row, col;
	cin>>row>>col;

	if (orr == 'h')
	{
		for (int i = col; i < (col + 5) ; i++)
		{
			area[row][i] = 'A';
		}
	}

	if (orr == 'v')
	{
		for (int i = row; i < (row + 5) ; i++)
		{
			area[i][col] = 'A';
		}
	}

	show(area);
}

main()
{
	char x = '*';
	int count = 0;
	char area[20][20] = {{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
		{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
		{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
		{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
		{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
		{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
		{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
		{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
		{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
		{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x}
	};
	x = '-';
	char hidd[20][20] = {{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
		{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
		{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
		{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
		{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
		{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
		{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
		{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
		{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},
		{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x},{x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x}
	};


	show(area);

	for(int i = 0; i<5 ; i++)
	{
		input(area);
	}

	for(int i = 0; i<5 ; i++)
	{
		count += attack(area,hidd);
	}


	show(area);
	cout<<"\n\nYou Hit "<<count<<" Times";
	return 0;
}