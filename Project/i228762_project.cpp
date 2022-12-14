//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Battleship.
//============================================================================

#ifndef Battleship_CPP_
#define Battleship_CPP_
#include "util.h"
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <string>
#include <cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 * */
void Timer(int m)
{

	// implement your functionality here
	// moveObject();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}



int width = 1020, height = 660;
int xx, yy;
int PlaceNum = 1, AttackNum = 1;

int PlayerScore = 0;
int EnemyScore = 0;

string Name = "";

bool AttTurns = true;
int ShipsLoc[10][2];
int AttackLocPlayer[250][3];
int AttackLocEnemy[250][3];

int EnemyArr[10][10] = { {0, 0, 0, 1, 0, 0, 1, 0, 0, 0}
						,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
						,{0, 1, 1, 1, 0, 0, 0, 1, 1, 0}
						,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
						,{0, 0, 0, 1, 1, 0, 0, 1, 1, 0}
						,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
						,{0, 0, 0, 1, 0, 0, 1, 0, 0, 0}
						,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
						,{0, 1, 1, 1, 0, 0, 0, 0, 0, 0}
						,{0, 0, 0, 0, 0, 1, 1, 1, 1, 0}};

// array for location on the grid
int PlayerArr[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
						,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
						,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
						,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
						,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
						,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
						,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
						,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
						,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
						,{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
// seed the random numbers generator by current time (see the documentation of srand for further help)...


/*
 * Main Canvas drawing function.
 */
void Consol()
{
	cout << endl
		 << endl
		 << endl
		 << "PLAYER ARRAY" << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << PlayerArr[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl
		 << "ENEMY ARRAY" << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << EnemyArr[i][j] << " ";
		}
		cout << endl;
	}

	cout << "xx ="<<xx<<endl;
	cout << "yy ="<<yy<<endl;
	cout << "PlaceNum ="<<PlaceNum<<endl;
	cout << "AttackNum ="<<AttackNum<<endl;
	cout << "EnemyScore ="<<EnemyScore<<endl;
	cout << "PlayerScore ="<<PlayerScore<<endl;
	if (AttTurns == true)
	{
		cout<<"Player Attacked";
	}
	if (AttTurns == false)
	{
		cout<<"Enemy Attacked";
	}
	


}

int COLOR = 68;

void Menu() /*MENU SCREEN*/
{

	glClearColor(1, 1, 1, 1);	  // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); // Update the colors

	DrawRoundRect(400, 500, 200, 50, colors[BLUE_VIOLET], 5);
	DrawString(420, 520, "Start", colors[WHITE]);

	DrawRoundRect(400, 400, 200, 50, colors[BLUE_VIOLET], 5);
	DrawString(420, 420, "Leader Board", colors[WHITE]);

	DrawRoundRect(400, 300, 200, 50, colors[BLUE_VIOLET], 5);
	DrawString(420, 320, "Rules", colors[WHITE]);

//selelet coloor
	DrawString(450, 250, "Select Color", colors[BLUE_VIOLET]);

	DrawRoundRect(400, 180, 90, 50, colors[GREEN], 5);
	DrawString(415, 200, "GREEN", colors[WHITE]);

	DrawRoundRect(510, 180, 90, 50, colors[BLUE], 5);
	DrawString(530, 200, "BLUE", colors[WHITE]);

	DrawString(335, 100, "Name :", colors[BLUE_VIOLET]);
	DrawString(400, 100, Name, colors[BLUE_VIOLET]);
		

	DrawRoundRect(10, 10, 90, 35, colors[RED], 5);
	DrawString(30, 20, "Quit", colors[WHITE]);

	glutSwapBuffers();
}

void LeaderBoard() /*Leaderboasrd*/
{

	glClearColor(1, 1, 1, 1);	  // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); // Update the colors

	// DrawRectangle(630, 390, 90, 30, colors[BLUE_VIOLET]);
	// DrawRectangle(630, 330, 90, 30, colors[BLUE_VIOLET]);
	
	
	DrawString(420,500,"Hamna Ahmed", colors[MEDIUM_PURPLE]);
	DrawString(600,500,"700", colors[MEDIUM_PURPLE]);
	
	DrawString(420,470,"Abdul Rafay", colors[MEDIUM_PURPLE]);
	DrawString(600,470,"640", colors[MEDIUM_PURPLE]);
	
	DrawString(420,440,"Saif Jillani", colors[MEDIUM_PURPLE]);
	DrawString(600,440,"600", colors[MEDIUM_PURPLE]);
	
	DrawString(420,410,"Hashim Ali", colors[MEDIUM_PURPLE]);
	DrawString(600,410,"560", colors[MEDIUM_PURPLE]);
	
	DrawString(420,380,"Diyam Hassan", colors[MEDIUM_PURPLE]);
	DrawString(600,380,"540", colors[MEDIUM_PURPLE]);
	
	DrawString(420,350,"Huda Hassan", colors[MEDIUM_PURPLE]);
	DrawString(600,350,"500", colors[MEDIUM_PURPLE]);
	
	DrawString(420,320,"Humdia Hassan", colors[MEDIUM_PURPLE]);
	DrawString(600,320,"440", colors[MEDIUM_PURPLE]);
	
	DrawString(420,290,"Wajeeh Rehman", colors[MEDIUM_PURPLE]);
	DrawString(600,290,"440", colors[MEDIUM_PURPLE]);
	
	DrawString(420,260,"Wasi Rehman", colors[MEDIUM_PURPLE]);
	DrawString(600,260,"420", colors[MEDIUM_PURPLE]);
	
	DrawString(420,230,"Hadia Emaan", colors[MEDIUM_PURPLE]);
	DrawString(600,230,"380", colors[MEDIUM_PURPLE]);
	
	
	glutSwapBuffers();
}

void Rules() /*Rules*/
{

	glClearColor(1, 1, 1, 1);	  // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); // Update the colors/ 30/ 30/ 30

	DrawString(400,500,"!----PLAY GAME AND ENJOY---!", colors[MEDIUM_PURPLE]);
	

	glutSwapBuffers();
}

void EnemyGrid() /*show grid*/
{

	// Horixantal lineee for grid
	DrawLine(630, 300, 930, 300, 4, colors[BLUE_VIOLET]);
	for (int i = 0; i < 300; i += 30)
	{
		DrawLine(630, 300 + i, 930, 300 + i, 2, colors[BLUE_VIOLET]);
	}
	DrawLine(630, 600, 930, 600, 4, colors[BLUE_VIOLET]);

	// Verxticall lineee for grid
	DrawLine(630, 300, 630, 600, 4, colors[BLUE_VIOLET]);
	for (int i = 0; i < 300; i += 30)
	{
		DrawLine(630 + i, 300, 630 + i, 600, 2, colors[BLUE_VIOLET]);
	}
	DrawLine(930, 300, 930, 600, 4, colors[BLUE_VIOLET]);
}

void MyGrid() /*show grid*/
{

	// Horixantal lineee for grid
	DrawLine(90, 300, 390, 300, 4, colors[BLUE_VIOLET]);
	for (int i = 0; i < 300; i += 30)
	{
		DrawLine(90, 300 + i, 390, 300 + i, 2, colors[BLUE_VIOLET]);
	}
	DrawLine(90, 600, 390, 600, 4, colors[BLUE_VIOLET]);
	// Verxticall lineee for grid
	DrawLine(90, 300, 90, 600, 4, colors[BLUE_VIOLET]);
	for (int i = 0; i < 300; i += 30)
	{
		DrawLine(90 + i, 300, 90 + i, 600, 2, colors[BLUE_VIOLET]);
	}
	DrawLine(390, 300, 390, 600, 4, colors[BLUE_VIOLET]);
}


void CheckWin()//check if player win!!
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			bool win = false;
			if (PlayerArr[i][j] == 1)
			{
				win = false;
			}
			if (win == true)
			{
				//Enemy Wins
				DrawString(420,100,"--!!ENEMY WINS!!--", colors[MEDIUM_PURPLE]);
			}
		}
	}
	

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			bool win = false;
			if (EnemyArr[i][j] == 1)
			{
				win = false;
			}
			if (win == true)
			{
				//Enemy Wins
				DrawString(420,100,"--!!PLAYER WINS!!--", colors[MEDIUM_PURPLE]);
			}
		}
	}
}


void OverlapVal() //validate if ships overlap
{
	for (int i = 0; i < PlaceNum-1; i++)
	{
		if (PlaceNum <= 4 )
		{
			if ((ShipsLoc[PlaceNum][0] == ShipsLoc[i][0]) && (ShipsLoc[PlaceNum][1] == ShipsLoc[i][1]))
			PlaceNum --;
		}
		else if (PlaceNum <= 7)
		{
			if ((ShipsLoc[PlaceNum][0] == ShipsLoc[i][0]) && (ShipsLoc[PlaceNum][1] == ShipsLoc[i][1]) ||
				(ShipsLoc[PlaceNum][0]+30 == ShipsLoc[i][0]) && (ShipsLoc[PlaceNum][1] == ShipsLoc[i][1]))
			PlaceNum --;
		}
		else if (PlaceNum <= 9)
		{
			if ((ShipsLoc[PlaceNum][0] == ShipsLoc[i][0]) && (ShipsLoc[PlaceNum][1] == ShipsLoc[i][1]) ||
				(ShipsLoc[PlaceNum][0]+30 == ShipsLoc[i][0]) && (ShipsLoc[PlaceNum][1] == ShipsLoc[i][1]) || 
				(ShipsLoc[PlaceNum][0]+60 == ShipsLoc[i][0]) && (ShipsLoc[PlaceNum][1] == ShipsLoc[i][1]))
			PlaceNum --;
		}
		else if (PlaceNum <= 10)
		{
			if ((ShipsLoc[PlaceNum][0] == ShipsLoc[i][0]) && (ShipsLoc[PlaceNum][1] == ShipsLoc[i][1]) ||
				(ShipsLoc[PlaceNum][0]+30  == ShipsLoc[i][0]) && (ShipsLoc[PlaceNum][1] == ShipsLoc[i][1]) || 
				(ShipsLoc[PlaceNum][0]+60  == ShipsLoc[i][0]) && (ShipsLoc[PlaceNum][1] == ShipsLoc[i][1])|| 
				(ShipsLoc[PlaceNum][0]+90 == ShipsLoc[i][0]) && (ShipsLoc[PlaceNum][1] == ShipsLoc[i][1]))
			PlaceNum --;
		}
	}
}

void MainGrid() //draw main grid
{
		// MAIN GRID
	// Horixantal GRID
	for (int i = 0; i < height; i += 30)
	{
		if (i % 90 == 0)
			DrawLine(0, i, width, i, 2, colors[BLACKO]);
		else
			DrawLine(0, i, width, i, 1, colors[BLACKO]);
	}
	// Vertical Grid
	for (int i = 0; i < width; i += 30)
	{
		if (i % 90 == 0)
			DrawLine(i, 0, i, width, 2, colors[BLACKO]);
		else
			DrawLine(i, 0, i, width, 1, colors[BLACKO]);
	}
}

void EnemyAttacksOnPlayer() //showing enemy attacks on player
{
static int MissCountEnem = 0;
	// for (int i = 10; i > 0; i--)
	// {
	// 	Timer(1);
	// 	DrawString(450,600,"Your Turn in  Seconds..",colors[BLUE_VIOLET]);
	// }
	// "+i+"
	if (AttTurns == false)
	{

		int randx = GetRandInRange(0 , 10);
		int randy = GetRandInRange(0 , 10);
		cout<<"\nRnadX = "<<randx;
		cout<<"\nRnadY = "<<randy;
		int RandPosx = (randx * 30 ) + 90;
		int RandPosy = 570 - (randy * 30 );

		if (PlayerArr[randy][randx] == 7)
		{
			EnemyAttacksOnPlayer();
		}
		else if (PlayerArr[randy][randx] == 1)
		{
			// for ( int i =0 ; i < 3 ; i++)
			// {
			// sleep(1);
			// cout<<"\nTime "<<3-i<<" Left\n";
			// }
			PlayerArr[randy][randx] = 7;
			AttackLocEnemy[AttackNum][0] = RandPosx;
			AttackLocEnemy[AttackNum][1] = RandPosy;
			AttackLocEnemy[AttackNum][2] =  1;
			EnemyScore +=60;//scoer
			MissCountEnem = 0;
			AttTurns = true;
			// the event that ship is blasted
		}
		else if (PlayerArr[randy][randx] == 0)
		{
			// for ( int i =0 ; i < 3 ; i++)
			// {
			// sleep(1);
			// cout<<"\nTime "<<3-i<<" Left\n";
			// }
			PlayerArr[randy][randx] = 7;
			AttackLocEnemy[AttackNum][0] = RandPosx;
			AttackLocEnemy[AttackNum][1] = RandPosy;
			AttackLocEnemy[AttackNum][2] =  0;
			
			MissCountEnem ++;
			if (MissCountEnem >= 2)
			{
			EnemyScore -=20;//scoer
			}

			AttTurns = true;
			// the event that ship is missed

		
		}
		
	Consol();

	}

	

	glutSwapBuffers();
}

void AttackDraw() //Attacks BY Player on enemy
{
	for (int i = 0; i < AttackNum; i++)
	{
	if (AttackLocPlayer[i][2] == 1) //If it Hits
	{
		DrawSquare(AttackLocPlayer[i][0], AttackLocPlayer[i][1], 30, colors[RED]);
	}
	else if (AttackLocPlayer[i][2] == 0) //if Misses
	{
		DrawSquare(AttackLocPlayer[i][0], AttackLocPlayer[i][1], 30, colors[POWDER_BLUE]);
	}
	else if (AttackLocPlayer[i][2] == 9) //Already Attacked position
	{
		AttackNum --;
		//do Nothing :) //Go back
	}
	// }


	// for (int i = 0; i < AttackNum+1; i++) //Enemy Attacks Dispaly
	// {
		if (AttackLocEnemy[i+1][2] == 1) //If it Hits
		{
			DrawSquare(AttackLocEnemy[i+1][0], AttackLocEnemy[i+1][1], 30, colors[RED]);
		}
		else if (AttackLocEnemy[i+1][2] == 0) //if Misses
		{
			DrawSquare(AttackLocEnemy[i+1][0], AttackLocEnemy[i+1][1], 30, colors[POWDER_BLUE]);
		}
	}


	glutSwapBuffers(); // do not modify this line..

}

	static bool CheckDrag;

void ShipPlace() /*SHIPS PLACMENT*/
{
	glClearColor(.99, .99, .99, 1); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT);	// Update the colors

	MainGrid();
	MyGrid();
	// DrawString(30, 760, "PLACE YOUR SHIPS!", colors[BLACK])


	if(CheckDrag == false)
	{
		DrawRoundRect(90, 240, 50, 30, colors[POWDER_BLUE], 0);
		DrawString(100, 250, "Auto", colors[WHITE]);

		if (PlaceNum == 1)
		{
			// 4 ships of 1
			DrawSquare(xx, yy, 30, colors[COLOR]);
			DrawSquare(600, 510, 30, colors[COLOR]);
			DrawSquare(660, 510, 30, colors[COLOR]);
			DrawSquare(720, 510, 30, colors[COLOR]);
			// 3 ships of 2
			DrawRectangle(540, 450, 60, 30, colors[COLOR]);
			DrawRectangle(540, 390, 60, 30, colors[COLOR]);
			DrawRectangle(540, 330, 60, 30, colors[COLOR]);
			// 2 ships of 3
			DrawRectangle(630, 390, 90, 30, colors[COLOR]);
			DrawRectangle(630, 330, 90, 30, colors[COLOR]);
			// 1 ships of 4
			DrawRectangle(630, 450, 120, 30, colors[COLOR]);

			ShipsLoc[0][0] = xx - (xx % 30);
			ShipsLoc[0][1] = yy - (yy % 30);
			
		}
		else if (PlaceNum == 2)
		{
			DrawSquare(ShipsLoc[0][0], ShipsLoc[0][1], 30, colors[COLOR]);
			DrawSquare(xx, yy, 30, colors[COLOR]);
			DrawSquare(660, 510, 30, colors[COLOR]);
			DrawSquare(720, 510, 30, colors[COLOR]);
			// 3 ships of 2
			DrawRectangle(540, 450, 60, 30, colors[COLOR]);
			DrawRectangle(540, 390, 60, 30, colors[COLOR]);
			DrawRectangle(540, 330, 60, 30, colors[COLOR]);
			// 2 ships of 3
			DrawRectangle(630, 390, 90, 30, colors[COLOR]);
			DrawRectangle(630, 330, 90, 30, colors[COLOR]);
			// 1 ships of 4
			DrawRectangle(630, 450, 120, 30, colors[COLOR]);
			ShipsLoc[1][0] = xx - (xx % 30);
			ShipsLoc[1][1] = yy - (yy % 30);
		}
		else if (PlaceNum == 3)
		{
			DrawSquare(ShipsLoc[0][0], ShipsLoc[0][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[1][0], ShipsLoc[1][1], 30, colors[COLOR]);
			DrawSquare(xx, yy, 30, colors[COLOR]);
			DrawSquare(720, 510, 30, colors[COLOR]);
			// 3 ships of 2
			DrawRectangle(540, 450, 60, 30, colors[COLOR]);
			DrawRectangle(540, 390, 60, 30, colors[COLOR]);
			DrawRectangle(540, 330, 60, 30, colors[COLOR]);
			// 2 ships of 3
			DrawRectangle(630, 390, 90, 30, colors[COLOR]);
			DrawRectangle(630, 330, 90, 30, colors[COLOR]);
			// 1 ships of 4
			DrawRectangle(630, 450, 120, 30, colors[COLOR]);
			ShipsLoc[2][0] = xx - (xx % 30);
			ShipsLoc[2][1] = yy - (yy % 30);
		}
		else if (PlaceNum == 4)
		{
			DrawSquare(ShipsLoc[0][0], ShipsLoc[0][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[1][0], ShipsLoc[1][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[2][0], ShipsLoc[2][1], 30, colors[COLOR]);
			DrawSquare(xx, yy, 30, colors[COLOR]);
			// 3 ships of 2
			DrawRectangle(540, 450, 60, 30, colors[COLOR]);
			DrawRectangle(540, 390, 60, 30, colors[COLOR]);
			DrawRectangle(540, 330, 60, 30, colors[COLOR]);
			// 2 ships of 3
			DrawRectangle(630, 390, 90, 30, colors[COLOR]);
			DrawRectangle(630, 330, 90, 30, colors[COLOR]);
			// 1 ships of 4
			DrawRectangle(630, 450, 120, 30, colors[COLOR]);
			ShipsLoc[3][0] = xx - (xx % 30);
			ShipsLoc[3][1] = yy - (yy % 30);
		}
		else if (PlaceNum == 5)
		{
			DrawSquare(ShipsLoc[0][0], ShipsLoc[0][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[1][0], ShipsLoc[1][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[2][0], ShipsLoc[2][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[3][0], ShipsLoc[3][1], 30, colors[COLOR]);
			// 3 ships of 2
			DrawRectangle(xx, yy, 60, 30, colors[COLOR]);
			DrawRectangle(540, 390, 60, 30, colors[COLOR]);
			DrawRectangle(540, 330, 60, 30, colors[COLOR]);
			// 2 ships of 3
			DrawRectangle(630, 390, 90, 30, colors[COLOR]);
			DrawRectangle(630, 330, 90, 30, colors[COLOR]);
			// 1 ships of 4
			DrawRectangle(630, 450, 120, 30, colors[COLOR]);
			ShipsLoc[4][0] = xx - (xx % 30);
			ShipsLoc[4][1] = yy - (yy % 30);
		}
		else if (PlaceNum == 6)
		{
			DrawSquare(ShipsLoc[0][0], ShipsLoc[0][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[1][0], ShipsLoc[1][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[2][0], ShipsLoc[2][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[3][0], ShipsLoc[3][1], 30, colors[COLOR]);
			// 3 ships of 2
			DrawRectangle(ShipsLoc[4][0], ShipsLoc[4][1], 60, 30, colors[COLOR]);
			DrawRectangle(xx, yy, 60, 30, colors[COLOR]);
			DrawRectangle(540, 330, 60, 30, colors[COLOR]);
			// 2 ships of 3
			DrawRectangle(630, 390, 90, 30, colors[COLOR]);
			DrawRectangle(630, 330, 90, 30, colors[COLOR]);
			// 1 ships of 4
			DrawRectangle(630, 450, 120, 30, colors[COLOR]);
			ShipsLoc[5][0] = xx - (xx % 30);
			ShipsLoc[5][1] = yy - (yy % 30);
		}
		else if (PlaceNum == 7)
		{
			DrawSquare(ShipsLoc[0][0], ShipsLoc[0][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[1][0], ShipsLoc[1][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[2][0], ShipsLoc[2][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[3][0], ShipsLoc[3][1], 30, colors[COLOR]);
			// 3 ships of 2
			DrawRectangle(ShipsLoc[4][0], ShipsLoc[4][1], 60, 30, colors[COLOR]);
			DrawRectangle(ShipsLoc[5][0], ShipsLoc[5][1], 60, 30, colors[COLOR]);
			DrawRectangle(xx, yy, 60, 30, colors[COLOR]);
			// 2 ships of 3
			DrawRectangle(630, 390, 90, 30, colors[COLOR]);
			DrawRectangle(630, 330, 90, 30, colors[COLOR]);
			// 1 ships of 4
			DrawRectangle(630, 450, 120, 30, colors[COLOR]);
			ShipsLoc[6][0] = xx - (xx % 30);
			ShipsLoc[6][1] = yy - (yy % 30);
		}
		else if (PlaceNum == 8)
		{
			DrawSquare(ShipsLoc[0][0], ShipsLoc[0][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[1][0], ShipsLoc[1][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[2][0], ShipsLoc[2][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[3][0], ShipsLoc[3][1], 30, colors[COLOR]);
			// 3 ships of 2
			DrawRectangle(ShipsLoc[4][0], ShipsLoc[4][1], 60, 30, colors[COLOR]);
			DrawRectangle(ShipsLoc[5][0], ShipsLoc[5][1], 60, 30, colors[COLOR]);
			DrawRectangle(ShipsLoc[6][0], ShipsLoc[6][1], 60, 30, colors[COLOR]);
			// 2 ships of 3
			DrawRectangle(xx, yy, 90, 30, colors[COLOR]);
			DrawRectangle(630, 330, 90, 30, colors[COLOR]);
			// 1 ships of 4
			DrawRectangle(630, 450, 120, 30, colors[COLOR]);
			ShipsLoc[7][0] = xx - (xx % 30);
			ShipsLoc[7][1] = yy - (yy % 30);
		}
		else if (PlaceNum == 9)
		{
			DrawSquare(ShipsLoc[0][0], ShipsLoc[0][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[1][0], ShipsLoc[1][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[2][0], ShipsLoc[2][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[3][0], ShipsLoc[3][1], 30, colors[COLOR]);
			// 3 ships of 2
			DrawRectangle(ShipsLoc[4][0], ShipsLoc[4][1], 60, 30, colors[COLOR]);
			DrawRectangle(ShipsLoc[5][0], ShipsLoc[5][1], 60, 30, colors[COLOR]);
			DrawRectangle(ShipsLoc[6][0], ShipsLoc[6][1], 60, 30, colors[COLOR]);
			// 2 ships of 3
			DrawRectangle(ShipsLoc[7][0], ShipsLoc[7][1], 90, 30, colors[COLOR]);
			DrawRectangle(xx, yy, 90, 30, colors[COLOR]);
			// 1 ships of 4
			DrawRectangle(630, 450, 120, 30, colors[COLOR]);
			ShipsLoc[8][0] = xx - (xx % 30);
			ShipsLoc[8][1] = yy - (yy % 30);
		}
		else if (PlaceNum == 10)
		{
			DrawSquare(ShipsLoc[0][0], ShipsLoc[0][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[1][0], ShipsLoc[1][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[2][0], ShipsLoc[2][1], 30, colors[COLOR]);
			DrawSquare(ShipsLoc[3][0], ShipsLoc[3][1], 30, colors[COLOR]);
			// 3 ships of 2
			DrawRectangle(ShipsLoc[4][0], ShipsLoc[4][1], 60, 30, colors[COLOR]);
			DrawRectangle(ShipsLoc[5][0], ShipsLoc[5][1], 60, 30, colors[COLOR]);
			DrawRectangle(ShipsLoc[6][0], ShipsLoc[6][1], 60, 30, colors[COLOR]);
			// 2 ships of 3
			DrawRectangle(ShipsLoc[7][0], ShipsLoc[7][1], 90, 30, colors[COLOR]);
			DrawRectangle(ShipsLoc[8][0], ShipsLoc[8][1], 90, 30, colors[COLOR]);
			// 1 ships of 4
			DrawRectangle(xx, yy, 120, 30, colors[COLOR]);
			ShipsLoc[9][0] = xx - (xx % 30);
			ShipsLoc[9][1] = yy - (yy % 30);
		}
	}
		
		if (PlaceNum > 10)
		{
			CheckDrag = true;
		}
		

	if (PlaceNum > 10 && CheckDrag == true)
	{
		DrawSquare(ShipsLoc[0][0], ShipsLoc[0][1], 30, colors[COLOR]);
		DrawSquare(ShipsLoc[1][0], ShipsLoc[1][1], 30, colors[COLOR]);
		DrawSquare(ShipsLoc[2][0], ShipsLoc[2][1], 30, colors[COLOR]);
		DrawSquare(ShipsLoc[3][0], ShipsLoc[3][1], 30, colors[COLOR]);
		// 3 ships of 2
		DrawRectangle(ShipsLoc[4][0], ShipsLoc[4][1], 60, 30, colors[COLOR]);
		DrawRectangle(ShipsLoc[5][0], ShipsLoc[5][1], 60, 30, colors[COLOR]);
		DrawRectangle(ShipsLoc[6][0], ShipsLoc[6][1], 60, 30, colors[COLOR]);
		// 2 ships of 3
		DrawRectangle(ShipsLoc[7][0], ShipsLoc[7][1], 90, 30, colors[COLOR]);
		DrawRectangle(ShipsLoc[8][0], ShipsLoc[8][1], 90, 30, colors[COLOR]);
		// 1 ships of 4
		DrawRectangle(ShipsLoc[9][0], ShipsLoc[9][1], 120, 30, colors[COLOR]);

		// translate into back-end!!
		static bool OneTime = false;
		if (OneTime == false) //backend Player Arr
		{
			for (int i = 0; i < 10; i++)
			{
				int tempx = ((ShipsLoc[i][0] - 90) / 30);		// x translation
				int tempy = 10 - ((ShipsLoc[i][1] - 270) / 30); // y translation
				
				if (i <= 3)
				{
					PlayerArr[tempy][tempx] = 1;
				}
				else if (i <= 6)
				{
					PlayerArr[tempy][tempx] = 1;
					PlayerArr[tempy][tempx + 1] = 1;
				}
				else if (i <= 8)
				{
					PlayerArr[tempy][tempx] = 1;
					PlayerArr[tempy][tempx + 1] = 1;
					PlayerArr[tempy][tempx + 2] = 1;
				}
				else if (i <= 9)
				{
					PlayerArr[tempy][tempx] = 1;
					PlayerArr[tempy][tempx + 1] = 1;
					PlayerArr[tempy][tempx + 2] = 1;
					PlayerArr[tempy][tempx + 3] = 1;
				}
			}
			OneTime = true;
		}

		//Enemy's entryy
		EnemyGrid();
		
				ostringstream scrP;
		ostringstream scrE;


		scrP<<"\r"<<PlayerScore;
		string tempScPl = scrP.str();
		
		DrawString(90,180,"Player Score :", colors[MEDIUM_PURPLE]);
		DrawString(230,180,tempScPl, colors[MEDIUM_PURPLE]);
		DrawString(90,140,"Balance : 500", colors[MEDIUM_PURPLE]);

		scrE<<"\r"<<EnemyScore;
		string tempScEm = scrE.str();
		
		DrawString(660,180,"Enemy Score :", colors[MEDIUM_PURPLE]);
		DrawString(800,180,tempScEm, colors[MEDIUM_PURPLE]);

		if ((xx > 630 && xx < 930) && (yy > 300 && yy < 600))
		{
			DrawString(xx - 8, yy - 8, "X", colors[RED]);
		}

	}
		AttackDraw();
		EnemyAttacksOnPlayer();

	// drawObject();

	glutSwapBuffers(); // do not modify this line..
}



/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */

	static bool NameCheck = false;

void KeysToShips(unsigned char key, int x, int y) //keys events 
{ // Printable keys fun
	y = height - y;
	static int MissCountPlay = 0;

	if (NameCheck == false)
	{
		// if (key == 8)
		// {
		// 	Name += "\b";
		// }
		if (key == 13)
		{
			NameCheck = true;
			// return;
		}
		Name += key;
	}

	
	if (key == 27 /* Escape key ASCII*/)
	{
		exit(1); // exit the program when escape key is pressed.
	}
	static bool CheckPlaced = false;

	//4 ships of 1 not goin' out of box
	if (PlaceNum <= 4 && CheckPlaced == false && (key == 'a' || key == 'A') && (x > 90 && x < 390) && (y > 300 && y < 600)) // Key for placing the bomb
	{
		PlaceNum++;
		OverlapVal();
		Consol();
	}
	//3 ships of 2 not goin' out of box
	else if (PlaceNum <= 7 && CheckPlaced == false && (key == 'a' || key == 'A') && (x > 90 && x < 360) && (y > 300 && y < 600)) // Key for placing the bomb
	{
		PlaceNum++;
		OverlapVal();
		Consol();
	}
	//2 ships of 3 not goin' out of box
	else if (PlaceNum <= 9 && CheckPlaced == false && (key == 'a' || key == 'A') && (x > 90 && x < 330) && (y > 300 && y < 600)) // Key for placing the bomb
	{
		PlaceNum++;
		OverlapVal();
		Consol();
	}
	//1 ships of 4 not goin' out of box
	else if (PlaceNum <= 10 && CheckPlaced == false && (key == 'a' || key == 'A') && (x > 90 && x < 300) && (y > 300 && y < 600)) // Key for placing the bomb
	{
		PlaceNum++;
		OverlapVal();
		if (PlaceNum > 10)
		{
			CheckPlaced = true;
		}
		Consol();
	}


	static bool CheckAuto;
	if ((key == 'A' || key == 'a')&& (x > 90 && x < 140) && (y < 270 && y > 240)&& CheckAuto == false)
	{
		ShipsLoc[0][0]= 90;		ShipsLoc[0][1]= 570;
		ShipsLoc[1][0]= 150;	ShipsLoc[1][1]= 540;
		ShipsLoc[2][0]= 240;	ShipsLoc[2][1]= 570;
		ShipsLoc[3][0]= 210;	ShipsLoc[3][1]= 510;
		ShipsLoc[4][0]= 300;	ShipsLoc[4][1]= 540;
		ShipsLoc[5][0]= 120;	ShipsLoc[5][1]= 420;
		ShipsLoc[6][0]= 210;	ShipsLoc[6][1]= 450;
		ShipsLoc[7][0]= 180;	ShipsLoc[7][1]= 330;
		ShipsLoc[8][0]= 300;	ShipsLoc[8][1]= 300;
		ShipsLoc[9][0]= 240;	ShipsLoc[9][1]= 390;
			PlaceNum = 11;
			CheckDrag = true;
			CheckAuto = true;
			CheckPlaced = true;
	}
	
	

	if (CheckPlaced == true && AttTurns == true && (key == 'x' || key == 'X') && (x > 630 && x < 930) && (y > 300 && y < 600)) // Key for placing the bomb
	{
	
	// if (sleep(1) == 0 )
	// {
	// 	AttackNum++;
	// 	AttTurns = false;
	// 	return;
	// }

		//&& AttTurns == true 
		int Attackx = x - (x % 30);
		int Attacky = y - (y % 30);

		int tempx = ((Attackx - 630) / 30); 	 // x translation
		int tempy = 10 - ((Attacky - 270) / 30); // y translation
	
	
		if (EnemyArr[tempy][tempx] == 1)
		{
			AttackLocPlayer[AttackNum][2] = 1;
			PlayerScore +=60;//scoer
			MissCountPlay = 0;

			// the event that ship is blasted
		}
		else if (EnemyArr[tempy][tempx] == 0)
		{
			AttackLocPlayer[AttackNum][2] = 0;
			MissCountPlay ++;
			if (MissCountPlay >= 2)
			{
			PlayerScore -=20;//scoer
			}
			// the event that ship is missed
		}
		else if (EnemyArr[tempy][tempx] == 7)
		{
			AttackLocPlayer[AttackNum][2] = 9;
		}
		cout << "XXXX pressed" << endl;
		
		AttackLocPlayer[AttackNum][0] = Attackx;
		AttackLocPlayer[AttackNum][1] = Attacky;
		
		EnemyArr[tempy][tempx] = 7;

		// glutDisplayFunc(AttackDraw);

		AttackNum++;
		AttTurns = false;
		Consol();

		EnemyAttacksOnPlayer();
	}




	glutPostRedisplay();
}


/*This function is called (automatically) whenever your mouse moves witin inside the game window
 * You will have to add the necessary code here for finding the direction of shooting
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 * */
void MousePressedAndMoved(int x, int y)
{
	y = height - y;

	// cout << x << " " << y << endl;
	glutPostRedisplay();
}

void Ship101(int x, int y) ///Mouse Drag 
{
	y = height - y;
	// cout << x << ">>>>>>>" << y << endl;
	if (PlaceNum < 11)
	{
		xx = x;
		yy = y;
	}

	glutPostRedisplay();
}

void MouseMoved(int x, int y)
{
	y = height - y;

	// cout << x << "|||" << y << endl;

	glutPostRedisplay();
}

void AttackAim(int x, int y)
{
	y = height - y;
	if (AttackNum < 100 && PlaceNum > 10)
	{
		if ((x > 630 && x < 930) && (y > 300 && y < 600))
		{
			DrawString(x - 8, y - 8, "X", colors[RED]);
		}

	}
	// cout << x << "|||" << y << endl;
	glutPostRedisplay();
	glutSwapBuffers();
}


void MenuClick(int button, int state, int x, int y)
{
	y = height - y;
	// cout << x << "/////" << y << endl;

	if (button == GLUT_LEFT_BUTTON ) // dealing only with left button
	{
		static bool check;
		if ((x > 400 && x < 600) && (y < 550 && y > 500)&& check == false)
		{
			glutDisplayFunc(ShipPlace);
			check = true;
		}
		else if ((x > 400 && x < 600) && (y < 450 && y > 400)&& check == false)
		{
			glutDisplayFunc(LeaderBoard);
			check = true;
		}
		else if ((x > 400 && x < 600) && (y < 350 && y > 300)&& check == false)
		{
			glutDisplayFunc(Rules);
			check = true;
		}
		else if ((x > 400 && x < 490) && (y < 230 && y > 180)&& check == false)
		{
			COLOR = 31;
		}
		else if ((x > 400 && x < 490) && (y < 230 && y > 180)&& check == false)
		{
			COLOR = 68;
		}
		else if ((x > 10 && x < 100) && (y < 45 && y > 10)&& check == false)
		{
			exit(1);
		}
	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
		cout << "Right Button Pressed" << endl;
	}
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 * You will have to add the necessary code here for shooting, etc.
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 * */
void MouseClicked(int button, int state, int x, int y)
{
	y = height - y;
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;
	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
		cout << "Right Button Pressed" << endl;
	}
	glutPostRedisplay();
}



/*a
 * our gateway main function
 * */
int main(int argc, char *argv[])
{

	InitRandomizer();							  // seed the random number generator...
	glutInit(&argc, argv);						  // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50);				  // set the initial position of our window
	glutInitWindowSize(width, height);			  // set the size of our window
	glutCreateWindow("Battleship Game");		  // set the title of our game window
	SetCanvasSize(width, height);				  // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	// glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutTimerFunc(1000.0, Timer, 0); // This function tells the library to call our Timer function after 1000.0/FPS milliseconds...

	glutDisplayFunc(Menu); // tell library which function to call for drawing Canvas.

	glutKeyboardFunc(KeysToShips); // tell library which function to call for printable ASCII characters


	glutMouseFunc(MenuClick); // mouse click on menu
	//
	glutMotionFunc(Ship101); // Mouse
	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* Battleship_CPP_ */
