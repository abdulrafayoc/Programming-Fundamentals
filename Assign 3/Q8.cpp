/*
Abdul Rafay
22i-8762
SE-B
*/
#include <iostream>
using namespace std;

int age(int day, int month, int year);
int discount(int age, string name, string lpostal, string wpostal, float income);

int main()
{
	string name, lpostal, wpostal;
	int day, month, year;
	float income;
//getting credentionals
	cout<<"Enter your name :";
	getline (cin, name);
	
	cout<<"Enter your day of birth [DD] :";
	cin>>day;
	if (day < 00 || day > 31)
    {
        cout<<"Enter correct input : ";
        cin>>day;
    }
	//input validations of date of birth
	cout<<"Enter your month of birth [MM] :";
	cin>>month;
	if (month < 00 || month > 12)
    {
        cout<<"Enter correct input : ";
        cin>>month;
	}
	cout<<"Enter your year of birth [YYYY] :";
	cin>>year;
	if (year < 1900 || year > 2022)
    {
        cout<<"Enter correct input : ";
        cin>>year;
    }
	cout<<"Enter your Postal Code of city you live in :";
	cin>>lpostal;
	
	cout<<"Enter your Postal Code of city you work in :";
	cin>>wpostal;
	
	cout<<"Enter your Monthly income :";
	cin>>income;
	if (income < 0)
    {
        cout<<"Enter correct input : ";
        cin>>income;
    }

	cout<<"Congratulations	"<<name<<"!"<<endl;
	cout<<"You are eligible for discount of "<<discount(age(day, month, year), name, lpostal, wpostal, income)<<"%";
	
	
return 0;
}
//function for calculation of age
int age(int day, int month, int year) 
{
		int age;

		age = 2022 - year;
		if (month > 11)
		{
			age -=1;
		}	
		return age;
}

//checking the discounts
int discount(int age, string name, string lpostal, string wpostal, float income)
{
		if (income < 10000)
		{
			return 90;
		}
		else if (age < 22)
		{
			return 50;
		}
		//checking postal code status of cities 
		else if (((lpostal.at(0) == '4' && lpostal.at(2) == '3') ||  (lpostal.at(0) == '5' && (lpostal.at(2) == '5' || lpostal.at(2) == '3'))) 
		&& ((wpostal.at(0) != '4' && wpostal.at(2) != '3') ||  (wpostal.at(0) != '5' && (wpostal.at(2) != '5' || wpostal.at(2) != '3'))))
		{
			return 20;
		}
		else
		{
			return 0;
		}

			
}