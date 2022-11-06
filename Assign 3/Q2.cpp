/*
Abdul Rafay
22i-8762
SE-B
*/
#include <iostream>

using namespace std;

int getswitchstatus();
int gethandleleft();
int gethandleright(); 
int getgearshift();
int validate();
//declaring all variables for all componemts
bool switch1, switch2, childlock, masterunlock, inhad1, inhad2, outhad1, outhad2;
char gear;

int getgearshift()
{
    cout<<"Enter Gear : ";
	cin>>gear;
	switch (gear)
	{
		case 'P':
            getswitchstatus();
            return 0;

        case 'N':
        case 'D':
        case '1':
        case '2':
        case '3':
        case 'R':
            cout<<"-----------------"<<endl
				<<"No door opens! \n"
				<<"-----------------"<<endl;
                    return 0;
	}
	return 0;
}


int getswitchstatus()
{
	//checking the status of the switches
    cout<<"Enter Dashboard Left Switch Status | ON [1] - OFF [0] | : ";
	cin>>switch1;
    cout<<"Enter Dashboard Right Switch Status | ON [1] - OFF [0] | : ";
    cin>>switch2;
    cout<<"Enter Child Lock Switch Status | ON [1] - OFF [0] | : ";
    cin>>childlock;
    cout<<"Enter Master Unlock Switch Status | ON [1] - OFF [0] | : ";
    cin>>masterunlock;

	switch(masterunlock)
    {
        case 1:

            switch(switch1)
            {
                case 1:
                    gethandleleft();
                case 0:
                    break;
            }
            switch(switch2)
            {
                case 1:
                    gethandleright();
                    break;

                case 0:
                    break;
            }
        break;

        case 0:
            cout<<"-----------------"<<endl
						<<"No door opens! \n"
						<<"-----------------"<<endl;
            return 0;
            break;
    }
    return 0;
}

//calculation of left door

int gethandleleft()
{

    cout<<"Enter Left Inside Handle Status | OPEN [1] - CLOSE [0] | : ";
	cin>>inhad1;
    cout<<"Enter Left Outside Handle Status | OPEN [1] - CLOSE [0] | : ";
    cin>>outhad1;
	switch(inhad1)
    {
        case 1:
            switch(childlock)
            {
                case 0:
                    cout<<"-----------------"<<endl
						<<"Left door opens! \n"
						<<"-----------------"<<endl;
                    break;
            }
            
            switch(outhad1)
            {
                case 1:
                    cout<<"-----------------"<<endl
						<<"Left door opens! \n"
						<<"-----------------"<<endl;
                    break;
                case 0:
                    break;
            }
        break;

        case 0:
            switch(outhad1)
            {
                case 1:
                    cout<<"-----------------"<<endl
						<<"Left door opens! \n"
						<<"-----------------"<<endl;
                    break;
                case 0:
                    break;
            }
        break;
    }
}

//calculation of left door

int gethandleright()
{
    cout<<"Enter Right Inside Handle Status | OPEN [1] - CLOSE [0] | : ";
	cin>>inhad2;
    cout<<"Enter Right Outside Handle Status | OPEN [1] - CLOSE [0] | : ";
    cin>>outhad2;

    switch(inhad2)
    {
        case 1:
            switch(childlock)
            {
                case 1:
                    break;

                case 0:
                    cout<<"-----------------"<<endl
						<<"Right door opens! \n"
						<<"-----------------"<<endl;
                    return 0;
                    break;
            }
            
            switch(outhad2)
        	{
    	        case 1:
                	cout<<"-----------------"<<endl
						<<"Right door opens! \n"
						<<"-----------------"<<endl;
            	    return 0;
        	        break;

    	        case 0:
            	    cout<<"-----------------"<<endl
						<<"No door opens! \n"
						<<"-----------------"<<endl;
        	        return 0;
    	            break;
	        }
        break;
        case 0:
            switch(outhad2)
        {
            case 1:
                cout<<"-----------------"<<endl
					<<"Right door opens! \n"
					<<"-----------------"<<endl;
                return 0;
                break;
            case 0:
                cout<<"-----------------"<<endl
					<<"No door opens! \n"
					<<"-----------------"<<endl;
                return 0;
                break;
        }
            break;
    }
    return 0;
}

//main function

int main()
{
	getgearshift();
	return 0;
}
