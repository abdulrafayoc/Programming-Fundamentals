
#include<iostream>
#include<cmath>
using namespace std;
float area(int radius)
{
    return (3.141592653589793238 * pow(radius, 2));
}
float area(int base, int height)
{
    return (0.5 * base * height);
}
float area(int base1, int base2, int height)
{
    return ((base1 + base2) / 2) * height;
}
int main()
{
    int choice;
	float height, base, base1, base2, radius , a;
    cout << "1: Circle\n 2: Triangle\n 3: Trapizium  "<<endl
		<<"Select the shape you want its area to be calculated: ";
    cin >> choice;
    switch (choice)
    {
        case 1:
				cout<<"Enter radius: ";
                cin>>radius;
                a = area(radius);
                cout << "Area: " << a;
				break;
        case 2:
				cout<<"Enter base: ";
                cin>>base;
                cout<<"Enter height: ";
                cin>>height;
                a = area(base, height);
                cout << "Area: " << a;
                break;
        case 3:
			   cout<<"Enter base1: ";
               cin>>base1;
               cout<<"Enter base2: ";
               cin>>base2;
               cout<<"Enter height: ";
               cin>>height;
               a = area(base1, base2, height);
               cout << "Area: " << a;
               break;
    default: cout << "Invalid Input";
                 break;
        }
    return 0;
}