#include<iostream>
#include<math.h>
using namespace std;

int isprime(int n)
{
    int i,j;
     j = sqrt(n);
    for(i=2; i<=j ; i++)
    {
        if(n%i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
 {
	//code
	int i,n,t,flag,tem;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    flag = 0;
	    int k,j = sqrt(n);
	    for(i=2; i<=j; i++)
	    {
	        k = n/i;
	        if(i * k == n)
	        {
	            if(k >= i)
	            {
	                if(isprime(k))
	                {
	                    cout<<k<<"\n";
	                    flag = 1;
	                    break;
	                }
	                if(isprime(i))
                    {
                        tem = i;
                        flag = 2;
                    }
	            }
	        }
	    }
	    if(flag == 0)
	    {
	        cout<<n<<"\n";
	    }
	    else if(flag == 2)
        {
            cout<<tem<<"\n";
        }
	}
	return 0;
}