#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream SubhanAllah;
	SubhanAllah.open("SubhanAllah.txt",ios::in);

	ifstream wahhh;
	wahhh.open("wahhh.txt",ios::in);
	
	string Text;
	

	ofstream merged;
	merged.open("merged.txt",ios::out);

	while (getline (SubhanAllah, Text)) 
	{
		merged << Text;
	}
	
	while (getline (wahhh, Text)) 
	{
  		merged << Text;
	}
	SubhanAllah.close();
	cout<<"done!";
	
	return 0;
}
