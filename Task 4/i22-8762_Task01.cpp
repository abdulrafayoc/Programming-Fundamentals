#include <iostream>
using namespace std;
int main()

{ 

	string name, color;
	int day, month, year;
	
	cout << "Enter your name!" <<endl;
	getline (cin, name);
	
	
	cout << "Enter your Day of Birth!" <<endl;
	cin >> day;
	
	cout << "Enter your month of Birth!" <<endl;
	cin >> month;
	
	cout << "Enter your Year of Birth!" <<endl;
	cin >> year;
	
	cout << "Enter your Favourite color!" <<endl;
	cin >> color;
	
	
	
	cout << "Your name is " <<name<<endl;
	cout << "Your date of Birth is " <<day<<"-"<<month<<"-"<<year<<endl;
	cout << "Your Favourite color is " <<color<<endl;
	
	return 0;
	
}
