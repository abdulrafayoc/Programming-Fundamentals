#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

string look(char ch);
string cipher(string text);
string de_cipher(string msg);


int bin2dec(int n)
{
	int dec = 0, i = 0, rem;

	while (n!=0)
	{
		rem = n % 10;
		n /= 10;
		dec += rem * pow(2, i);
		++i;
	}
	return dec;
}

string cipher(string text)
{
	string cipher = "";
	for(int i = 0 ; i < text.length() ; i++)
	{
		cipher += look(text.at(i));
	}
	return cipher;
}

string de_cipher(string msg)
{
	string temp;
	string decripted = "";
	for (int k = 0, count = 0; k < msg.length()/5 ; k++, count += 5)
	{
		temp = "";
		for (int i = count ; i < count+5 ; i++)
		{
			temp += msg.at(i);
		}
		
		stringstream hello;
		hello << temp ;
		int bin;
		hello >> bin;
		if (bin == 11111)
		{
			decripted += char(32);
		}
		else
		{
			int dec = bin2dec(bin);
			decripted += char(dec+97);
		}
	}
	return decripted;
}


long long int dec2bin(int num)
{
	int bin = 0, dec = 1;
	while(num > 0)
	{
		bin += (num % 2) * dec;
		dec *= 10;
		num /= 2;
	}
	return bin;
}
string look(char ch)
{
	int num , bin;
	
	if (int(ch) == 32)
	{
		bin = 11111;
	}
	else if (int(ch)<97)
	{
		num = int(ch) - 65;
		bin = dec2bin(num);
	}
	else
	{
		num = int(ch) - 97;
		bin = dec2bin(num);
	}

	stringstream hello;
	hello << setw(5) << setfill('0') << bin;
	string code = hello.str();
	
	return code;
}

int main()
{
	cout<<"Enter Message : ";
	string msg;
	getline(cin,msg);

	string cipherd = cipher(msg);

	cout<<"This is end to end Encripted : "<<cipherd<<endl;

	string dcipher = de_cipher(cipherd);

	cout<<"Decripted : "<<dcipher;

}