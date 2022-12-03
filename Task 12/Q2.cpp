#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	int larr[5];
	int uarr[5];
	int count;
	
	for (int i = 0 ; i < 5 ; i++ )
	{
		cout<<"Enter "<<i+1<<" number = ";
		cin>>uarr[i];
	}
	
	srand(time(NULL));
	for (int i = 0 ; i < 5 ; i++ )
	{
		larr[i] =rand()%10;
		cout<<larr[i];
	}

	
	for (int j = 0 ; j < 5 ; j++ )
	{
		for (int k = j+1  ; k < 5  ; k++ )
		{
			if (larr[j] == uarr [k])
			{
				count ++;
			}
		}
	}
	
	if (count == 0)
	cout <<"You got all answers Wrong!";

	cout <<"You got " << count  <<" answer(s) right!";
	
	return 0;
}
