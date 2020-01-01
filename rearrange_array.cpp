#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	//code
	long long  i,j,n,t,tem;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    long long a[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
        long long mi = 0, mx = n-1,max = a[n-1] + 1;
        for(i=0;i<n;i++)
        {
            if(i%2 == 0)
            {
                a[i] = (max * (a[mx] %max)) + a[i];
                //a[i] = a[i]/max;
                mx--;
            }
            else
            {
                a[i] = (max * (a[mi] %max)) + a[i];
                //a[i] = a[i]/max;
                mi++;
            }
        }
        for(i=0; i<n; i++)
        {
            a[i] = (a[i] / max);
        }
	    for(i=0;i<n;i++)
	    {
	        cout<<a[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}