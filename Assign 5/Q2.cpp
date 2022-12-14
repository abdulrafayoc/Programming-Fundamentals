#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

string substring(int start, int end, string text);


string invert (string text)
{

	string temp = "";
	for(int i = text.length() - 1; i >= 0; i--)
	{
		temp += text[i];
	}

	return temp;

}

string replace(string pattern, string text, int start, int end)
{
    string toReturn = "";
   for(int i = 0; i < start; i++)
   {
       toReturn += text[i];
   }
   for(int i = 0; i < pattern.length(); i++)
   {
        toReturn += pattern[i];
   }
   for(int i = end; i < text.length(); i++)
   {
        toReturn += text[i];
   }

    return toReturn;
}

int find(string pattern, string text)
{
	for (int j = 0; j < text.length(); j++)
	{
		for (int i = 0; i < pattern.length(); i++)
		{
			if (pattern[i] == text[j+i])
			{
				if (i == pattern.length()-1)
					return j;
			}
		}
	}
}

string substring(int start, int end, string text)
{
	string temp;
	for (int i = start-1; i < end; i++)
	{
		temp += text[i];
	}
	return temp;
}

main()
{
	cout<<"Enter Message : ";
	string msg;
	getline(cin,msg);
	int mode;
	cout<<"Enter Mode : \n"
		<<"[1] Extract Substring from Message \n"
		<<"[2] Find Text in Message \n"
		<<"[3] Replace text in Message\n"
		<<"[4] Invert the Message\n";
	cin>>mode;
	switch(mode)
	{
		case 1:
		{
			int start,end;
			cout<<"Enter Start index of Substring : ";
			cin>>start;
			cout<<"Enter End index of Substring : ";
			cin>>end;
			cout <<endl<< substring(start,end,msg)<<endl;
			break;
			
		}
		case 2:
		{
			string text;
			cout<<"Enter text you want to Find : ";
			cin>>text;
			cout <<endl<< find(text, msg)<<endl;
			break;	
		}
		case 3:
		{
			int start,end;
			cout<<"Enter Start index of text you want to Replace : ";
			cin>>start;
			cout<<"Enter End index of text you want to Replace : ";
			cin>>end;
			
			string text;
			cout<<"Enter text you want to replace with : ";
			cin>>text;
			cout<<endl<< replace(text, msg, start, end+1)<<endl;
			break;
		}
		case 4:
		{
			cout<<endl<<invert (msg)<<endl;
			break;
		}
		default:
		{
			cout<<"\nInvalid Input";
			break;
		}
	}
}

