#include <iostream>
#include <windows.h>
#include <iomanip>
#include <stdlib.h>
#include <bits/stdc++.h>


using namespace std;

void show(int maze[9][16])
{
	system("cls");
	for(int i=0; i<9; i++)
	{
		cout<<endl;
		for(int j=0; j<16; j++)
		{
			cout<<setw(02)<<maze[i][j]<<"  ";
		}
	}
}

void findMouse(int& mx, int& my, int maze[9][16])
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			if (maze[i][j] == 80)
			{
				mx = i;
				my = j;
			}
		}
	}
}

void checkwinx(int mx,int my,int maze[9][16])
{
	if (maze[mx+1][my] == 90 || maze[mx-1][my] == 90)
	{
		cout<<"\n-0-------0--000---0-------0---0-"
			<<"\n-0-------0---0----0-0-----0---0-"
			<<"\n-0-------0---0----0--0----0---0-"
			<<"\n-0---0---0---0----0---0---0---0-"
			<<"\n-0--0-0--0---0----0----0--0---0-"
			<<"\n-0-0---0-0---0----0-----0-0-----"
			<<"\n-0-------0--000---0-------0---0-";
			sleep(1000);
	}
}   

void checkwiny(int mx,int my,int maze[9][16])
{
	if (maze [mx][my+1] == 90 || maze [mx][my-1] == 90)
	{
		cout<<"\n-0-------0--000---0-------0---0-"
			<<"\n-0-------0---0----0-0-----0---0-"
			<<"\n-0-------0---0----0--0----0---0-"
			<<"\n-0---0---0---0----0---0---0---0-"
			<<"\n-0--0-0--0---0----0----0--0---0-"
			<<"\n-0-0---0-0---0----0-----0-0-----"
			<<"\n-0-------0--000---0-------0---0-";
			sleep(1000);
	}
}                   
void runMouse(int maze[9][16])
{                   
	// cout<<endl<<mx<<endl<<my;

	while (1)
	{
		int mx, my;        
		findMouse(mx,my,maze);
		show(maze);
		sleep(.9);
		srand(time(0));
		int rdm = rand() % 4;
		
		checkwiny(mx,my,maze);
		checkwinx(mx,my,maze);
	
		if (rdm == 0 && maze[mx][my-1] == 0)
		{
			maze[mx][my-1] = 80;
			maze[mx][my] = 0;
		}
		else if (rdm == 1 && maze[mx][my+1] == 0)
		{	
			maze[mx][my+1] = 80;
			maze[mx][my] = 0;		
		}
		else if (rdm == 2 && maze[mx-1][my] == 0)
		{
			maze[mx-1][my] = 80;
			maze[mx][my] = 0;
		}
		else if (rdm == 3 && maze[mx+1][my] == 0)
		{
			maze[mx+1][my] = 80;
			maze[mx][my] = 0;
		}
	}

}


int main()
{
	const int ROWS = 9,COLUMNS = 16;
	int O = 42,C = 90,M = 80,o = -1,_ = 0;
	int maze[ROWS][COLUMNS]=   {{ O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O },
								{ O, _, _, _, _, _, _, _, _, _, o, _, _, _, _, O },
								{ O, _, o, _, o, o, o, _, o, _, o, _, o, o, o, O },
								{ O, _, o, _, o, o, o, _, o, _, o, o, o, o, o, O },
								{ O, _, o, _, o, _, o, _, _, _, o, _, _, _, _, O },
								{ O, _, o, _, o, _, o, _, o, M, o, _, o, o, _, O },
								{ O, C, o, _, o, _, o, _, o, _, o, _, o, o, _, O },
								{ O, _, _, _, _, _, _, _, _, _, _, _, o, o, _, O },
								{ O, O, O, O, O, O, O, O, O, O, O, O, O, O, O, O }
	};	
	show(maze);
	runMouse(maze);
}