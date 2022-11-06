#include<iostream>
using namespace std;
main()
{
    cout << "Enter a 5 digit number: ";
    int number, reminder, div, sum = 0;
    cin >> number;
    while (number > 0)
    {
        reminder = number % 10;
        sum = sum + reminder;
        number = number / 10;
    }
    cout << "The sum of the digits is: " << sum;
    return 0;
}