/*  
Abdul Rafay
22i-8762
SE-B
*/
#include <iostream>
using namespace std;
//declaring variables
int s1, s2, e1, e2;
int validate(int A);
int validate(int D, int M, int Y);

//getting time of appiontments
int getttime()
{
    cout<<"Enter the start time of 1st appointment"<<endl;
    cin>>s1;
    s1 = validate(s1);
    cout<<"Enter the end time of 1st appointment"<<endl;
    cin>>e1;
    e1 = validate(e1);
    cout<<"--------------------------------------"<<endl;
    cout<<"Enter the start time of 2nd appointment"<<endl;
    cin>>s2;
    s2 = validate(s2);
    cout<<"Enter the end time of 2nd appointment"<<endl;
    cin>>e2;
    s1 = validate(e2);

    return 0;
}


int d1, d2, m1, m2, y1, y2;
//checking if the apps overlaps
int getdate()
{
    cout<<"Enter the date of 1st appointment [DD]"<<endl;
    cin>>d1;
    d1 = validate(d1, m1, y1);
    cout<<"Enter the month of 1st appointment [MM]"<<endl;
    cin>>m1;
    m1 = validate(d1, m1, y1);
    cout<<"Enter the year of 1st appointment [YY]"<<endl;
    cin>>y1;
    y1 = validate(d1, m1, y1);
    cout<<"--------------------------------------"<<endl;
    cout<<"Enter the date of 2nd appointment [DD]"<<endl;
    cin>>d2;
    d2 = validate(d2, m2, y2);
    cout<<"Enter the month of 2nd appointment [MM]"<<endl;
    cin>>m2;
    m2 = validate(d2, m2, y2);
	cout<<"Enter the year of 2nd appointment [YY]"<<endl;
    cin>>y2;
    y2 = validate(d2, m2, y2);
    return 0;
}

//checking if the appointments 
int isoverlapping()
{
    if ((d1 == d2) && (m1 == m2) && (y1 == y2))
    {
    	if ((s1 > e2 && e1 < s2) || (s1 < e2 && e1 > s2) )
    	{
        	cout<<"The appointment are Overlapping!"<<endl;
	    }
    	else
    	{
        	cout<<"The appointment are not Overlapping!"<<endl;
    	}    
    }
    else
    {
    	cout<<"The appointment are not Overlapping!"<<endl;
	}
    
}
int validate(int A)
{
	//input validation of 
    if (A < 00 || A >= 24)
    {
        cout<<"Enter correct input : ";
        cin>>A;
        return A;
    }
    return A;
}

int validate(int D, int M, int Y)
{
	
    if (Y < 1900 || Y > 2022)
    {
        cout<<"Enter correct input : ";
        cin>>Y;
        return Y;
    }
    if (M < 00 || M > 12)
    {
        cout<<"Enter correct input : ";
        cin>>M;
        return M;
    }
    if (D < 00 || D > 31)
    {
        cout<<"Enter correct input : ";
        cin>>D;
        return D;
    }
}
//main function
int main()
{
    getttime();
    getdate();
    isoverlapping();

    return 0;
}