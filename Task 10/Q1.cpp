#include <iostream>

using namespace std;

float twith, tdep;

int bank(float rate , float bal , int mon)
{
    float dep, with;

    for (int i = 0; i < mon; i++)
    {
        
        {
        	cout<<"\nEnter Money Deposited in Month "<<i+1 << " : ";
        	cin >> dep;
        } while (dep < 0);
        
        tdep += dep;
        bal += dep;

        do
        {
            cout<<"Enter Money Withdrawl in Month "<<i+1 << " : ";
            cin >> with;
        } while (with < 0);
    	cout<<"\n----------------------------------------\n";
    	
    	twith += with;
        bal -= with;

        if (bal < 0)
        {
            cout<<"You have Negative Balance and your Account is Closed!";
            return bal;
        }

        bal += ((bal/100)*(rate/12));

    }
    return bal;
}


int main()
{
    float rate, bal;
    int mon;
    cout<<"!!Welcome to Maze Bank!!\n"
        <<"------------------------\n";

    cout<<"Enter Anuall Interest Rate : ";
    cin>>rate;
    cout<<"Enter Your Current Balance : ";
    cin>>bal;
    cout<<"Enter no.of Months since account was Established : ";
    cin>>mon;

    bal = bank(rate , bal , mon);

    cout<<"\nYour total amount Deposited is "<<tdep << " in "<<mon<<" Months\n";
    cout<<"Your total amount Withdrawl is "<<twith << " in "<<mon<<" Months\n";
    cout<<"your balance is "<<bal;
    
}
