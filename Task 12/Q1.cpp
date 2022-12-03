#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int arr[10];
	int x;
	int n1, n2;
	int curr;
	int prv;
	int minn = 9999999999;
	
	for (int i = 0 ; i < 10 ; i++ )
	{
		cout<<"Enter "<<i+1<<" term = ";
		cin>>arr[i];
	}
	
	cout<<"--------------------\nEnter X = ";
	cin>>x;
	
	for (int i = 0 ; i < 10 ; i++ )
	{
		for (int k = i+1 ; k < 10  ; k++ )
		{
			curr = x - (arr[i] + arr [k]);
		
			if (curr>0 && ((arr[i] + arr [k]) < x) )
			{
			if  (minn > curr)
			{
				minn = min(minn , curr);
				
				n1 = arr[i];
				n2 = arr[k];
			}
			
				if(arr[i]+arr[k]==x)
				{
					n1 = arr[i];
					n2 = arr[k];
        			break;
				}
			}
		}
	}
	
	
	cout <<"Numbers are "<< n1 << " and " << n2;

	
	
	return 0;
}
