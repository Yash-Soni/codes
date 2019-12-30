#include<iostream>
#include"algorithm"
using namespace std;

int main() {
	//code
	int i,n,t,a[100000],flag,max_sofar,max_here;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    max_sofar = 0;  max_here=0;
	    flag = 0;
	    for(i=0; i<n;i++)
	    {
	        max_here = max_here + a[i];
	        if(max_here < 0)
	        max_here = 0;
	        
	        else if(max_sofar < max_here)
	        {
	            max_sofar = max_here;
	            flag = 1;
	        }
	    }
	    if(flag == 0)
	    {
	        sort(a,a+n);
	        cout<<a[n-1];
	    }
	    else
	    {
	        cout<<max_sofar;
	    }
	    cout<<"\n";
	}
	return 0;
}