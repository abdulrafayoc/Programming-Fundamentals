#include <iostream>
#include <fstream>

using namespace std;
main()
{
	ifstream wahhh;
	ofstream Encrypt;
	char maal;
int A;

	wahhh.open("wahhh.txt",ios::in);
	Encrypt.open("Encrypt.txt",ios::out);

	while(!wahhh.eof())
	{
		wahhh.get(maal);
		A = int(maal + 100) ;
		Encrypt << char(A);
	}
	
	Encrypt.close();
	cout<<"Done!";


	return 0;
}
