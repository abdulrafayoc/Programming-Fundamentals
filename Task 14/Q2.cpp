#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	fstream KimJon, john, peter;

	KimJon.open("wahhh.txt");

	KimJon << "The rose is red.\nA girl is playing there.\nThere is a playground.\nAn aeroplane is in the sky.\nNumbers are not allowed in the password.";

	char maal;
	
	string maaal;

	KimJon.close();

	john.open("wahhh.txt");
	
		while(!john.eof())
		{
			john.get(maal);
			cout<<maal;
		}
	

	john.close();
	int count;
	peter.open("wahhh.txt");
	while(!peter.eof())
	{
		peter.get(maal);
		count++;
	}
	cout<<count<<" Alphapects Found!!\n";
	peter.close();
	KimJon.open("wahhh.txt");
	count = 0;
	while(!KimJon.eof())
	{
		getline(KimJon, maaal, ' ');
		count++;
	}
	cout<<count<<" Words Found!!\n";
	KimJon.close();

	return 0;
}
