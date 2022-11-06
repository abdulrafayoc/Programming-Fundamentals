//Abdul Rafay 22i8762 SE-B
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	int sec = 0;
	
	int hours, mins , secs;
	
	cout<<"enter Seconds";
	cin>>sec;
	
	hours = (sec / 3600);
	mins = (sec / 60) % 60;
	secs = sec % 60;
	
	
	cout <<hours <<" "<<mins<<" "<<secs;

    return 0;
}