#include<iostream>
#include<iomanip>
#include<cmath>
#include<ctime>
#include<algorithm>

using namespace std;

int getHighestInRow(int mtrx1[3][3], int R)
{
    int max = mtrx1[R][0];
    for(int i = 0; i < 3; i++)
    {
        if(max < mtrx1[R][i])
        {
            max = mtrx1[R][i];
        }
    }
    return max;
}

int getLowestInRow(int mtrx1[3][3], int R)
{
    int min = mtrx1[R][0];
    for(int i = 0;i < 3; i++)
    {
        if(min > mtrx1[R][i])
        {
            min = mtrx1[R][i];
        }  
    }
    return min;
}

void multiply(int mtrx1[3][3],int Mtrx2[3][3]){
    int ResultMtrx[3][3];
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0;j < 3;j++)
        {
            ResultMtrx[i][j] = 0;
            for(int l = 0 ; l < 3 ; l++)
            {
                ResultMtrx[i][j] += mtrx1[i][l] * Mtrx2[l][j];
            }
            cout << ResultMtrx[i][j] << "\t";
        }
        cout << endl;
    } 
}

int main()
{
    int Mtrx1[3][3]={{4,8,12}, {2,34,24}, {7,28,100}},Mtrx2[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int mode;
    cout<<"Enter Mode : " 
        <<"[1].Get the highest number of a row" 
        <<"[2]Get the lowest number of a row" 
        <<"[3]multiply" << endl;
    cin>>mode;
    int R;
    if (mode == 1)
    {
        cout<<"Enter rows: " << endl;
        cin >> R; 
        cout << "The highest value = " << getHighestInRow(Mtrx1,R) << endl;
    }
    else if (mode == 2)
    {
    cout << "Enter row";
    cin >> R; 
    cout << "The lowest value = " << getLowestInRow(Mtrx1,R) << endl;                
    } 
    else if (mode == 3)
    {
    cout << "The product of the two matrices: ";
    multiply(Mtrx1,Mtrx2);
    }
}
