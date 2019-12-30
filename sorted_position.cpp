#include<iostream>
using namespace std;
int main()
 {
	//code
	int i,n,tem,j,t;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n], leftmax[n], rightmin[n];
	    for(i=0; i<n; i++)
	    {
	        cin>>a[i];
	        leftmax[i] = 0;
	        rightmin[i] = 0;
	    }
	    int max, min,flag =0;
	    max = a[0];      min = a[0];
	    for(i=0; i<n; i++)
	    {
	        if(max < a[i])
	        {
	            max = a[i];
	            leftmax[i] = max;
	        }
	        else
	        leftmax[i] = max;
	    }
	    min = a[n-1];
	    for(i=n-1; i>=0; i--)
	    {
	        if(min > a[i])
	        {
	            min = a[i];
	            rightmin[i] = min;
	        }
	        else
	        rightmin[i] = min;
	    }
	    
	    for(i=1; i<n-1; i++)
	    {
	        if((a[i] >= leftmax[i]) && (a[i] <= rightmin[i]))
	        {
	            cout<<a[i]<<"\n";
	            flag = 1;
	            break;
	        }
	    }
	    if(flag != 1)
	    {
	        cout<<"-1\n";
	    }
	}
	return 0;
}