#include<iostream>
#include<math.h>
#include<string.h>
#define ele (long long int)(pow(10,9) + 7)
using namespace std;

int fact(int n,int r)
{
    int C[r+1];
    memset(C,0,sizeof(C));
    
    C[0] = 1;
    for(int i =1; i<= n; i++)
    {
        for(int j = min(i,r); j>0; j--)
        {
            C[j] = (C[j-1] + C[j])%ele;
        }
    }
    return C[r];
}

int main()
 {
	//code
	int i,n,r,t,ans;
	cin>>t;
	while(t--)
	{
	    cin>>n>>r;
	    if(r>n)
	    {
	        cout<<"0\n";
	    }
	    else
	    {
	        int rem = n-r;
	        if(rem > r)
	            cout<<fact(n,rem)<<"\n";
	        else
	            cout<<fact(n,r)<<"\n";
	    }
	}
	return 0;
}