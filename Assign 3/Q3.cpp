/*
Abdul Rafay
22i-8762
SE-B
*/
#include <iostream>

using namespace std;

int main()
{
	string from, to;
	float value=1, result;

	cout<<"------Unit Conversion------\n";
	cout<<"fl.oz, gal, lb, oz, in, ft, mi  --> ml, l, kg, g, mm, cm, m, km"<<endl;
    cout<<"Convert from?";
    cin>>from;
    cout<<"Convert to?";
    cin>>to;
	cout<<"Value?";
    cin>>value;
    
	if (from == "fl.oz" && to == "ml")
	{
		result = value * 29.574; 
	}
    else if (from == "fl.oz" && to == "l")
	{
		result = value * 0.0295735;
	}
	else if (from == "gal" && to == "ml")
	{
		result = value * 3785.41;
	}
    else if (from == "gal" && to == "l")
	{
		result = value * 3.78541;
	}
	else if (from == "lb" && to == "kg")
	{
		result = value * 0.453592;
	}
    else if (from == "lb" && to == "g")
	{
		result = value * 453.6;
	}
    else if (from == "oz" && to == "kg")
	{
		result = value * 0.0283495;
	}
    else if (from == "oz" && to == "g")
	{
		result = value * 28.35;
	}
	else if (from == "in" && to == "mm")
	{
		result = value * 25.4;
	}
    else if (from == "in" && to == "cm")
	{
		result = value * 2.54;
	}
    else if (from == "in" && to == "m")
	{
		result = value * 0.0254;
	}
    else if (from == "in" && to == "km")
	{
		result = value * 0.0000254;
	}
	else if (from == "ft" && to == "mm")
	{
		result = value * 304.8;
	}
    else if (from == "ft" && to == "cm")
	{
		result = value * 30.48;
	}
    else if (from == "ft" && to == "m")
	{
		result = value * 0.3048;
	}
    else if (from == "ft" && to == "km")
	{
		result = value * 0.0003048;
	}
	else if (from == "mi" && to == "mm")
	{
		result = value * 1609340;
	}
    else if (from == "mi" && to == "cm")
	{
		result = value * 160934;
	}
    else if (from == "mi" && to == "m")
	{
		result = value * 1609.34;
	}
    else if (from == "mi" && to == "km")
	{
		result = value * 1.60934;
	}
    else
    {
        cout<<"Incorrect Inputs"<<endl
			<<"-------------------"<<endl<<endl;
        main();
        return 0;
    }
    
    cout<<value<<from<<" = "<<result<<to;
    return 0;
}