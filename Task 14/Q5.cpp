#include <iostream>
#include <fstream>

using namespace std;
main()
{
	ofstream Decrypt;
	ifstream Encrypt;
	int maal;
	char A;

	Encrypt.open("Encrypt.txt",ios::in);
	Decrypt.open("Decrypt.txt",ios::out);

	while(!Encrypt.eof())
	{
		Encrypt.get(A);
		maal = int(A) ;
		Decrypt << char(maal -	100);
	}
	
	Encrypt.close();
	Decrypt.close();
	cout<<"Done!";
	

	return 0;
}
