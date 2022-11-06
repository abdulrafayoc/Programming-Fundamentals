/*
Abdul Rafay
22i-8762
SE-B
*/
#include <iostream>
using namespace std;

int saver(char pkg, float bill, float gb);

int main()
{

    char pkg;
    float gb, mb;
    float bill;
    float tmp;
	//getting credentionals
	cout<<"What Pakage you are Subscribed to? : ";
    cin>>pkg;
    if (pkg != 'A' || pkg != 'B' || pkg != 'C')
    {
        cout<<"Enter correct Input : ";
        cin>>pkg;
    }
    
    cout<<"Enter Data used : ";
    cin>>gb;
    if (gb < 0)
    {
        cout<<"Enter correct Input : ";
        cin>>gb;
    }

    mb = gb * 1024;
//calculating bill!
    switch(pkg)
    {
        case 'A':
            bill = 100;
            if (gb > 2)     
            {   
            	//calculations of bill
                tmp = (mb - 2048) / 100;
                bill = bill + (tmp * 30);
            }  
        break;

        case 'B':
            bill = 250;
            if (gb > 5.5)     
            {
            	//calculations of bill
                tmp = (mb - 5632) / 100;
                bill = bill + (tmp * 20);
            }
        break;

        case 'C':
            bill = 1000;
        break;
    }    

    cout<<"Your due Amount is : "<<bill <<endl;
    
    saver(pkg, bill, gb);

return 0;

}

int saver(char pkg, float bill, float gb)
{
	switch(pkg)
    {
    	//checking if any money can be saved by A, B or C
        case 'A':
            if (gb < 2)
            {
                cout<<"You have subscried to right Package!";
            }
            else if (gb <= 5.5 && bill <= 1000)     
            {
                cout<<"You can save "<< (bill - 250) <<" by subscribing to Package B";   
            }
            else if (gb > 5.5 && bill >= 1000)
            {
                cout<<"You can save "<< (bill - 1000) <<" by subscribing to Package C";
            }
        break;

        case 'B':
            if (gb <= 2)
            {
                cout<<"You can save "<< (bill - 100) <<" by subscribing to Package A";
            }
            else if (bill < 1000)
            {
                cout<<"You have subscried to right Package!";
            }
            else if (gb > 5.5 && bill >= 1000)
            {
                cout<<"You can save "<< (bill - 1000) <<" by subscribing to Package C";
            }
        break;

        case 'C':
            if (gb <= 2)
            {
                cout<<"You can save "<< (bill - 100) <<" by subscribing to Package A";
            }
            else if (gb <= 5.5)     
            {
                cout<<"You can save "<< (bill - 250) <<" by subscribing to Package B";   
            }
            else
            {
				cout<<"You have subscried to right Package!";
			}
        break;
    }    
}