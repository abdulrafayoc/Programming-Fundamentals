/*
Abdul Rafay
22i-8762
SE-B
*/

#include <iostream>

using namespace std;

int decimal;
string roman;
//checking 1000s
int M()
{
	if (decimal >= 1000)
	{
		roman+= "M";
		decimal -= 1000;
		int  M();
	}
	return 0;
}

//checking 900s
int CM()
{
	if (decimal >= 900)
	{
		roman+= "CM";
		decimal -= 900;
		int  CM();
	}
	return 0;
}
//checking 500s
int D()
{
	if (decimal >= 500)
	{
		roman+= "D";
		decimal -= 500;
		int  D();
	}
	return 0;
}

//checking 400
int CD()
{
	if (decimal >= 400)
	{
		roman+= "CD";
		decimal -= 400;
		int  CD();
	}
	return 0;
}
//checking 100s
int C()
{
	if (decimal >= 100)
	{
		roman+= "C";
		decimal -= 100;
		int  C();
	}
	return 0;
}

//checking 90s
int XC()
{
	if (decimal >= 90)
	{
		roman+= "XC";
		decimal -= 90;
		int  XC();
	}
	return 0;
}

//checking 50s
int L()
{
	if (decimal >= 50)
	{
		roman+= "L";
		decimal -= 50;
		int  L();
	}
	return 0;
}

//checking 40s
int XL()
{
	if (decimal >= 40)
	{
		roman+= "XL";
		decimal -= 40;
		int  XL();
	}
	return 0;
}
//checking 10s
int X()
{
	if (decimal >= 10)
	{
		roman+= "X";
		decimal -= 10;
		int  X();
	}
	return 0;
}
//checking 9s
int  IX()
{
	if (decimal >= 9)
	{
		roman+= "IX";
		decimal -= 9;
		 IX();
	}
	return 0;
}
//checking 5s
int  V()
{
	if (decimal >= 5)
	{
		roman+= "V";
		decimal -= 5;
		 V();
	}
	return 0;
}
//checking 4s
int  IV()
{
	if (decimal >= 4)
	{
		roman+= "IV";
		decimal -= 4;
		 IV();
	}
	return 0;
}
//checking 1s
int  I()
{
	if (decimal >= 1)
	{
		roman+= "I";
		decimal -= 1;
		 I();
	}
	return 0;
}

int main()
{
	cout<<"decimal a decimal number";
	cin>>decimal;
	if (decimal < 1 || decimal > 3999)
	{
		cout<<"Invalid Roman Number Value";
		roman=" ";
		main();
	}
			//calling all functions
	 M();
	 CM();
	 D();
	 CD();
	 C();
	 XC();
	 L();
	 XL();
	 X();
	 IX();
	 V();
	 IV();
	 I();

	cout<<roman;
	return 0;

}
