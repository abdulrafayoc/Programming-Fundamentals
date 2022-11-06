#include <iostream>

using namespace std;


int checkPrimeNumber(int num)
{
    for (int i = 2; i < (num/2); i++)
    {
        if ((num % i) == 0)
        {
            cout<<"The number is a Prime Number!\n\n";
            return 0;
        }
        else
        {
            cout<<"The number is not a Prime Number!\n\n";
            return 0;
        }  
    }
    return 0;
    
}

int main()
{
	int num;
	cout<<"\nEnter a Positive Integer : ";
	cin>>num;

    if (num > 0)
    {
        checkPrimeNumber(num);
        main();
    }
    
}