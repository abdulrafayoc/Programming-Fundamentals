/*
Abdul Rafay
22i-8762
SE-B
*/
#include <iostream>

using namespace std;

//checking valid inputs
bool validate(bool& res)
{
	if (res != 1 || res != 0)
	{
		cout<<"Please Enter Correct Answer: ";
		cin>>res;
	}
	return res;
}


int main()
{
	int budget, price=0;
	//declaring all variables
	bool filer, automan, infotain, navsys, fogli, haled, inter, letsof, flrmt, drvis, trtray;

	cout<<"Enter your Budget for the Car: ";
	cin>>budget;
	//inputting all the choices
	cout<<"Are you a Tax Filer [1] or Non-filer [0]?: ";
	cin>>filer;

	(filer == 1) ? price += 25000 : price += 75000;

	cout<<"Do you want manual [0] or automatic [1] car?: ";
	cin>>automan;

	(automan == 0) ? price += 3769000 : price += 3899000;
	
	//inputting all the choices
	cout<<"Do you want infotainment system [1] or not [0]?: ";
	cin>>infotain;
	//advanced options
	if (infotain == 1)
	{
		cout<<"Do you want infotainment system with navigation system [1] or not [0]?: ";
		cin>>navsys;

		(navsys == 1) ? price += 59500 : price += 8000;
	}

	cout<<"Do you want Fog lights [1] or not [0]?: ";
	cin>>fogli;

	if (fogli == 1)
	{
		cout<<"Do you want halogen lights [1] or LED lights [0]?: ";
		cin>>haled;

		(haled == 1) ? price += 2000 : price += 5000; 
		
	}

	cout<<"Do you want High grade Interior[1] or not [0]?: ";
	cin>>inter;

	//advanced options

	if (inter == 1)
	{
		cout<<"Do you want Leather seats [1] or Sofa seats [0]?: ";
		cin>>letsof;


		(letsof == 1) ? price += 45000 : price += 25000; 
	
	}

	cout<<"Do you want Floot Mats [1] or not [0]?: ";
	cin>>flrmt;

	(flrmt == 1) ? price += 60000 : price += 00;
	

	cout<<"Do you want Door Visors?: ";
	cin>>drvis;

	(drvis == 1) ? price += 60000 : price += 00;

	cout<<"Do you want Trunk Tray [1] or not [0]??: ";
	cin>>trtray;

	(trtray == 1) ? price += 8500 : price += 00;
	
	cout<<endl<<endl<<"Your car's price is "<<price<<endl<<endl;
	
	//checking budget
	(budget < price) ? 
		cout<<"---------------------------------"<<endl
			<<"Sorry! You cant afford it."
	:
		cout<<"---------------------------------"<<endl
			<<"You have a good taste, go for it!";
}
