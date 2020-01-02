#include <iostream>
#include <algorithm>
#include"math.h"
using namespace std;

int calc(int x, int *y, int n, int *nofY)
{
    if(x == 0)
        return 0;
    if(x == 1)
        return nofY[0];
        
    int *idx;
    idx = upper_bound(y,y+n,x);
    int ans = (y+n) - idx;
    
    ans += nofY[0] + nofY[1];
    if(x == 2)
        ans -= nofY[3] + nofY[4];
    if(x == 3)
        ans += nofY[2];
    return ans;
}

int main() {
	//code
	long long int i,j,n,p,q,x,y,t,count;
	cin>>t;
	while(t--)
	{
	    cin>>x>>y;
	    int a[x], b[y];
	    for(i=0; i<x; i++)
	    cin>>a[i];
	    for(i=0; i<y; i++)
	    cin>>b[i];
	    
	    sort(a, a+x);
	    sort(b, b+y);
	    count = 0;      i = 0;      j = 0;
	    
	    int nofY[5] = {0};
	    for(i=0;i<y; i++)
	    {
	        if(b[i] < 5)
	        {
	            nofY[b[i]]++;
	        }
	    }
	    
	    for(i=0; i < x; i++)
	    {
	        count = count + calc(a[i], b, y, nofY);
	    }
	    cout<<count<<"\n";
	}
	return 0;
}