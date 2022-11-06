#include <iostream>

using namespace std;

int fun(char operations, int number1, int number2);

int main()
{
	char operations;
	int number1, number2;
	
cout	<<"MENU"<<endl
		<<"+ Addition"<<endl
		<<"- Subtraction"<<endl
		<<"* Mulitipication"<<endl
		<<"/ Division"<<endl
		<<"% Mod"<<endl;
	
cout	<<"1st number = ";
		cin>> number1;
cout	<<"2nd number = ";
		cin>> number2;
cout	<<"Enter operation = ";		
		cin>>operations;

fun(operations, number1, number2);
}

int fun(char operations, int number1, int number2)
{
	switch(operations){
	case '+':
		cout<<number1<<" + "<<number2<<" = "<<number1+number2;
		break;
	case '-':
		cout<<number1<<" - "<<number2<<" = "<<number1-number2;
		break;
	case '*':
		cout<<number1<<" * "<<number2<<" = "<<number1*number2;
		break;
	case '/':
			switch(number2)
			{
			case 0:
				cout << "Infinity";
				break;
			default:
				cout<<number1<<" / "<<number2<<" = "<<number1/number2;
				break;
			}
		break;
	default:
		cout<<"Error";
		break;
	}
	}	