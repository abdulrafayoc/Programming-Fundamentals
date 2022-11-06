//Abdul Rafay 22i8762 SE-B
#include <iostream>

using namespace std;

int main()
{
	
	int curY = 2022, curM = 10, curD = 1;
	int ageY, ageM, ageD;
		cout<<"Enter your age in Years: ";
		cin>>ageY;
		cout<<"Enter your age in Months: ";
		cin>>ageM;
		cout<<"Enter your age in Days: ";
		cin>>ageD;
		
	int birthY = curY - ageY, birthM = curM - ageM , birthD = curD - ageD;
	
	(birthM <= 0 ? (birthY --),(birthM += 12) : birthY = birthY) ; //fixing Month
	(birthD <= 0 ? (birthM --), ((birthM == 1 || birthM == 3 || birthM == 5 || birthM == 7 || birthM == 8 || birthM == 10 || birthM == 12) ? (birthD += 31) : ((birthM == 2) ? (((birthY % 4 == 0 && birthY % 100 != 0) || birthY % 400 == 0) ? birthD += 29 : birthD += 28) : birthD += 30)) :birthY=birthY); //fixing Date

	cout<<"You were born on Year "<<birthY<<" Month "<<birthM<<" Day "<<birthD<<endl;

	return 0;
}