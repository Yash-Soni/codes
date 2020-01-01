#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	//code
	int i,j,k,gap,tem,t,x,y;
	cin>>t;
	while(t--)
	{
	    cin>>x>>y;
	    int a[x], b[y];
	    for(i=0;i<x;i++)
	    cin>>a[i];
	    for(i=0;i<y;i++)
	    cin>>b[i];
	    k = x-1;
	    for(i = 0,j=0;i<x && j<y; )
	    {
	        if((a[i] >= b[j]))
	        {
	            tem = a[k];
	            a[k] = b[j];
	            b[j] = tem;
	            k--;
	           
	            j++;
	        }
	        i++;
	        
	    }
	    sort(a,a+x);
	    sort(b,b+y);
	    for(i=0;i<x;i++)
	    cout<<a[i]<<" ";
	    for(i=0;i<y;i++)
	    cout<<b[i]<<" ";
	    cout<<"\n";
	}
	return 0;
}